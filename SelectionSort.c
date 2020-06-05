#include<stdio.h>
#include<stdlib.h>

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
    int smallest = 0;
    int positionOfSmallest;
    int i,j;
    int t;
    for(i = 0; i < n; i++)
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

}