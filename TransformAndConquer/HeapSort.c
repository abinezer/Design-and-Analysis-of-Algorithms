#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


void HeapBottomUp(int unsortedArray[], int n)
{
    int i,j;
    int k;
    int v;
    int heap;
    for(i = floor(n/2); i >= 1; i--)
    {
        k = i;
        v = unsortedArray[k];
        heap = 0;
        while((heap == 0) && (2*k) <= n)
        {
            j = 2*k;
            if(j < n)
            {
                if(unsortedArray[j] < unsortedArray[j+1])
                {
                    j++;
                }
            }

            if(v >= unsortedArray[j])
            {
                heap = 1;
            }

            else
            {
                unsortedArray[k] = unsortedArray[j];
                k = j;
            }
        }

        unsortedArray[k] = v;
    }
}

void Heapsort(int unsortedArray[], int n)
{
    int t;
    if(n > 1)
    {
        t = unsortedArray[1];
        unsortedArray[1] = unsortedArray[n];
        unsortedArray[n] = t;
        n--;
        HeapBottomUp(unsortedArray, n);
        Heapsort(unsortedArray, n);
    }
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
    int unsortedArray[n+1];
    for(int k = 1; k <= n; k++)
    {
        printf("Enter the %dth element of the array: ", k);
        scanf("%d", &unsortedArray[k]);
    }
    double total_time;
	clock_t start, end;
	start = clock();
    srand(time(NULL));

    HeapBottomUp(unsortedArray, n);
    Heapsort(unsortedArray, n);

    for(int i = 1; i <= n; i++)
    {
        printf("%d ", unsortedArray[i]);
    }
    printf("\n");

    end = clock();
	//time count stops 
	total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	//calulate total time
    printf("total time taken: %lf \n", total_time);
}