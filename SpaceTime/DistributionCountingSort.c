#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int* DistributionSort(int unsortedArray[], int n, int l, int u)
{
    int i,j;
    int* S = malloc (sizeof (char) * n);
    int D[n];
    for(j = 0; j < u-l+1; j++)
    {
        D[j] = 0;
    }

    for(i = 0; i < n; i++)
    {
        D[unsortedArray[i] - l] = D[unsortedArray[i] - l] + 1;
    }

    for(j = 1; j < u-l+1; j++)
    {
        D[j] = D[j-1] + D[j];
    }

    for(i = n-1; i >= 0; i--)
    {
        j = unsortedArray[i] - l;
        S[D[j]-1] = unsortedArray[i];
        D[j] = D[j] - 1;
    }

    return S;
}

int main()
{
    int n;
    int l,u;
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

    printf("Enter lower limit:\n");
    scanf("%d", &l);
    printf("Enter upper limit:\n");
    scanf("%d", &u);

    double total_time;
	clock_t start, end;
	start = clock();
    srand(time(NULL));

    int* Sorted = DistributionSort(unsortedArray, n, l, u);

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