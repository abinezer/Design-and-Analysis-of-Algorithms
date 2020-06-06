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

    int i,j;
    int t;
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(unsortedArray[j] > unsortedArray[j+1])
            {
                t = unsortedArray[j];
                unsortedArray[j] = unsortedArray[j+1];
                unsortedArray[j+1] = t;
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
