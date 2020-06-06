#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
int factorial(int n) 
{ 
    if (n == 0) 
        return 1; 
    return n * factorial(n - 1); 
} 
*/

int cities[10][10];
int count = 0;
int sum = 0;
int min = 0;
//Prints the array 
void printArr(int a[],int n) 
{ 
    sum = 0;
	//for (int i=0; i<n; i++) 
	//	printf("%d ",a[i]); 
	//printf("\n");
    sum = sum + cities[0][a[0]];
    printf("%c to %c ",97, a[0]+97);
    int p;
    for(p = 0; p < n-1; p++)
    {
        int source = a[p];
        int dest = a[p+1];
        sum = sum + cities[source][dest];
        printf("%c to %c ", source+97, dest+97);
    }
    sum = sum + cities[a[p]][0];
    printf("%c to %c ", a[p]+97, 97);    
    printf("Sum of paths is %d \n", sum);
    count++;
    if(sum < min)
    {
        min = sum;
    }
} 

// Generating permutation using Heap Algorithm 
void heapPermutation(int a[], int size, int n) 
{ 
	// if size becomes 1 then prints the obtained 
	// permutation 
	if (size == 1) 
	{ 
		printArr(a, n); 
		return; 
	} 

    int temp;
	for (int i=0; i<size; i++) 
	{ 
		heapPermutation(a,size-1,n); 

		// if size is odd, swap first and last 
		// element 
		if (size%2==1) 
        {
			//swap(a[0], a[size-1]);
            temp = a[0];
            a[0] = a[size-1];
            a[size-1] = temp;
        } 

		// If size is even, swap ith and last 
		// element 
        else
        {
            //swap(a[i], a[size-1]); 
            temp = a[i];
            a[i] = a[size-1];
            a[size-1] = temp;
        }

	} 
} 

// Driver code 
int main()
{
    int n;
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    //int cities[n][n];
    int i,j;
    int distance;
    for(i = 0; i < n; i++)
    {
        for(j = i; j < n; j++)
        {
            if(j != i)
            {
                printf("Enter distance between city %c and %c: ",i+97,j+97);
                scanf("%d",&distance);
                min = min + distance;
                cities[i][j] = distance;
                cities[j][i] = distance;
            }

            else
            {
                cities[i][j] = 0;
            }
            
        }
    }
/*
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d   ", cities[i][j]);
        }
        printf("\n");
    }
*/
    int a[n-1];
    for(int k = 0; k < n-1; k++)
    {
        a[k] = k+1;
    } 
/*
    for(int k = 0; k < n-1; k++)
    {
        printf("%d", a[k]);
    }
    printf("\n \n");
*/
	int n1 = sizeof a/sizeof a[0]; 
	heapPermutation(a, n1, n1);
    //printf("%d\n", count); 

    printf("Minimum distance is %d \n",min);
	return 0; 
}