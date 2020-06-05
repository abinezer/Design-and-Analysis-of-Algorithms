#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{

    int n;
    printf("Enter the size of the array: \n");
    scanf("%d", &n);
    if(n <= 0)
    {
        printf("error \n");
        exit(0);
    }
    int unsortedArray[n];
    for(int k = 0; k < n; k++)
    {
        printf("Enter the %dth element of the array: ", k);
        scanf("%d", &unsortedArray[k]);
    }
    double total_time;
	clock_t start, end;
	start = clock();
    srand(time(NULL));
    int smallest = 0;
    int positionOfSmallest;
    int i,j;
    int t;
    for(i = 0; i < n-1; i++)
    {
        smallest = unsortedArray[i];
        positionOfSmallest = i;
        for(j = i; j < n; j++)
        {
            if(unsortedArray[j] < smallest)
            {
                smallest = unsortedArray[j];
                positionOfSmallest = j;      
            }
            if(smallest != unsortedArray[i])
            {
                t = unsortedArray[j];
                unsortedArray[j] = unsortedArray[i];
                unsortedArray[i] = t;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        printf("%d ",unsortedArray[i]);
    }
    printf("\n");

    end = clock();
	//time count stops 
	total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	//calulate total time
    printf("total time taken: %lf \n", total_time);

}