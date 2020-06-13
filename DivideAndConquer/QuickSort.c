#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Partition(int unsortedArray[], int StartIndex, int EndIndex)
{
    int i = StartIndex;
    int j = EndIndex + 1;
    int t;
    int p = unsortedArray[StartIndex];
    while(i < j)
    {
        do
        {
            i++;
        }while(unsortedArray[i] < p);

        do
        {
            j--;
        }while(unsortedArray[j] > p);

        t = unsortedArray[i];
        unsortedArray[i] = unsortedArray[j];
        unsortedArray[j] = t;
    }

    t = unsortedArray[i];
    unsortedArray[i] = unsortedArray[j];
    unsortedArray[j] = t;

    t = unsortedArray[StartIndex];
    unsortedArray[StartIndex] = unsortedArray[j];
    unsortedArray[j] = t;

    return j;
}

void QuickSort(int unsortedArray[], int StartIndex, int EndIndex)
{
    if(StartIndex < EndIndex)
    {
        int s = Partition(unsortedArray, StartIndex, EndIndex);
        QuickSort(unsortedArray, StartIndex, s);
        QuickSort(unsortedArray, s + 1, EndIndex);
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


    QuickSort(unsortedArray, 0, n-1);

    for(int p = 0; p < n; p++)
    {
        printf("%d ", unsortedArray[p]);
    }

    printf("\n");

    end = clock();
	//time count stops 
	total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	//calulate total time
    printf("total time taken: %lf \n", total_time);

}