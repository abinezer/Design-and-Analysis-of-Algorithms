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
    int unsortedArray[n+1];
    for(int k = 0; k < n; k++)
    {
        printf("Enter the %dth element of the array: ", k);
        scanf("%d", &unsortedArray[k]);
    }

    int SearchElement;
    printf("Enter the element to be searched: ");
    scanf("%d", &SearchElement);

    double total_time;
	clock_t start, end;
	start = clock();
    srand(time(NULL));

    int count = 0;
    int position;

    int j = 0;

    unsortedArray[n] = SearchElement;
    for(int i = 0; i < n+1; i++)
    {
        if(unsortedArray[i] == SearchElement && (i != n))
        {
            printf("Search Element found at position %d \n", i);
            count++;
        }

        else
        {
            if(unsortedArray[i] == SearchElement && count == 0)
            {
                printf("Element not found \n");
            }
        }
    }

    end = clock();
	//time count stops 
	total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	//calulate total time
    printf("total time taken: %lf \n", total_time);

}
