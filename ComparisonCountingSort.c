#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int* ComparisonSort(int unsortedArray[], int n)
{
    int i,j;
    int Count[n];
    int* S = malloc (sizeof (char) * n);
    for(i = 0; i < n; i++)
    {
        Count[i] = 0;
    }

    for(i = 0; i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(unsortedArray[i] < unsortedArray[j])
            {
                Count[j] = Count[j] + 1;
            }
            else
            {
                Count[i] = Count[i] + 1;
            }
            
        }
    }

    for(i = 0; i < n; i++)
    {
        S[Count[i]] = unsortedArray[i];
    }

    return S;
}

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

    int* Sorted = ComparisonSort(unsortedArray, n);

    for(int i = 0; i < n; i++)
    {
        printf("%d ", Sorted[i]);
    }

    printf("\n");

    end = clock();
	//time count stops 
	total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	//calulate total time
    printf("total time taken: %lf \n", total_time);

}