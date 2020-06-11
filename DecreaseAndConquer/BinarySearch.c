#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main()
{
    int LowerBound,MaxBound, mid;
    int SearchElement;
    int n;
    int flag = 0;
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
        printf("Enter the %dth element of the Sorted array: ", k);
        scanf("%d", &unsortedArray[k]);
    }

    printf("Enter the search element: ");
    scanf("%d", &SearchElement);

    double total_time;
	clock_t start, end;
	start = clock();
    srand(time(NULL));

    LowerBound = 0;
    MaxBound = n - 1;

    while(LowerBound < MaxBound)
    {
        mid = floor((LowerBound+MaxBound)/2);
        if(SearchElement == unsortedArray[mid])
        {
            printf("Search Element has been found at %d \n", mid);
            flag = 1;
            break;
        }

        else
        {
            if(SearchElement < mid)
            {
                MaxBound = mid - 1;
            }

            else
            {
                LowerBound = mid + 1;
            }
            
        }
    }

    if(flag != 1)
    {
        printf("Search Element not found \n");
    }
    end = clock();
	//time count stops 
	total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	//calulate total time
    printf("total time taken: %lf \n", total_time);
}