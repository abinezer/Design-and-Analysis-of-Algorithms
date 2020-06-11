#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    
    int n;
    int count;
    int countOfOnes = 0;
    int p = 0;
    int g = 0;
    int flag = 0;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int graph[n][n];
    int TopSortArray[n+1];
    int i,j,k;
    int connected;
    for(i = 0; i < n+1; i++)
    {
        TopSortArray[i] = -1;
    }

    printf("Enter 1 for connected and 0 for not connected \n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(j != i)
            {            
                printf("%c and %c: ",i+97,j+97);
                scanf("%d",&connected);
                graph[i][j] = connected;
                if(connected == 1)
                {
                    countOfOnes++;
                }
            }

            else
            {
                graph[i][j] = 0;
            }
            
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d   ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\n \n");

    while(countOfOnes != 0)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(graph[j][i] == 1)
                {
                    printf("exiting column %d \n", i);
                    break;
                } 

                else
                {
                    count++;
                }
                
            }

            if(count == n)
            {
                for(k = 0; k < n; k++)
                {
                    if(graph[i][k] == 1)
                    {
                        graph[i][k] = 0;
                        countOfOnes--;
                    }
                }
                g = 0;
                flag = 0;
                while(flag == 0 && g < n)
                {
                    if(TopSortArray[g] == i)
                    {
                        flag = 1;
                    }
                    g++;
                }

                if(flag == 0)
                {
                    TopSortArray[p++] = i;
                }
                
            }
            count = 0;
        }
        
    }
    

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d   ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i = 0; i < n; i++)
    {
        g = 0;
        flag = 0;
        while(flag == 0 && g < n)
        {
            if(TopSortArray[g] == i)
            {
                flag = 1;
            }
            g++;
        }
        if(flag == 0)
        {
            TopSortArray[p++] = i;
        }
    }

    for(i = 0; i < n; i++)
    {
        printf("%c \n", TopSortArray[i]+97);
    }
}