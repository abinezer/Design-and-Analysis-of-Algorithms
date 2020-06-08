#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//int count = 0;
int graph[10][10];
int GraphVertices[10];
int n;

void DFS(int p)
{
	printf("\n%c",p+97);
    
    GraphVertices[p] = 1;

	for(int j = 0;j < n;j++)
    {
        if((GraphVertices[j] == 0) && graph[p][j] == 1)
        {
            DFS(j);
        }
    }

}

int main()
{
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int i,j;
    int connected;

    printf("Enter 1 for connected and 0 for not connected \n");
    for(i = 0; i < n; i++)
    {
        for(j = i; j < n; j++)
        {
            if(j != i)
            {            
                printf("%c and %c: ",i+97,j+97);
                scanf("%d",&connected);
                graph[i][j] = connected;
                graph[j][i] = connected;
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

    for(i = 0; i < n; i++)
    {
       GraphVertices[i] = 0;    
    }

    for(int k = 0; k < n; k++)
    {
        if(GraphVertices[k] == 0)
        {
            DFS(k);
        } 
    }
    printf("\n");
/*
    for(i = 0; i < n; i++)
    {
        printf("%d", GraphVertices[i]);
    }
    printf("\n");
*/

}