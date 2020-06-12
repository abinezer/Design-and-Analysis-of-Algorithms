#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int count = 0;

void Merge(int* b, int* c, int* unsortedArray, int sizeOf_b, int sizeOf_c)
{
    printf("in merge \n");
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < sizeOf_b && j < sizeOf_c)
    {
        if(b[i] <= c[j])
        {
            unsortedArray[k] = b[i];
            i = i+1;
        }

        else
        {
            unsortedArray[k] = c[j];
            j = j+1;
        }

        k = k+1;
        
    }

    if(i == sizeOf_b)
    {
        while(j < sizeOf_c)
        {
            unsortedArray[k] = c[j];
            k++;
            j++;
        }
    }

    else
    {
        while(i < sizeOf_b)
        {
            unsortedArray[k] = b[i];
            i++;
            k++;
        }
    }
}

void MergeSort(int* ArrayOne, int sizeOfArrayOne)
{
    if(sizeOfArrayOne > 1)
    {
        printf("Mergesort %d \n", count++);
        int sizeOf_b = floor(sizeOfArrayOne/2);
        int b[sizeOf_b];
        int sizeOf_c =  sizeOfArrayOne - sizeOf_b;
        int c[sizeOf_c];
        int i,j = 0;
        for(i = 0; i < sizeOf_b; i++)
        {
            b[i] = ArrayOne[i];
        }

        while(i < sizeOfArrayOne)
        {
            c[j] = ArrayOne[i];
            i++;
            j++;
        }
        printf("array b: \n");
        for(i = 0; i < sizeOf_b; i++)
        {
            printf("%d ", b[i]);
        }     
        printf("\n");

        printf("array c: \n");
        for(i = 0; i < sizeOf_c; i++)
        {
            printf("%d ", c[i]);
        }
        printf("\n\n");

        MergeSort(b, sizeOf_b );
        MergeSort(c, sizeOf_c );
        Merge(b, c, ArrayOne, sizeOf_b, sizeOf_c);
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

    MergeSort(unsortedArray, n);

    for(int i = 0; i < n; i++)
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