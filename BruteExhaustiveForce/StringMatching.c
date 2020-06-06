//This is the brute force version of String matching.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main()
{
    int sizeOfString; int sizeOfPattern;
    printf("Enter the size of the string: \n");
    scanf("%d", &sizeOfString);
    char StringText[sizeOfString];
    printf("Enter the String: \n" );
    scanf("%s",StringText);
    //printf("StringText: %s \n", StringText);
    printf("Enter the size of Pattern: \n");
    scanf("%d", &sizeOfPattern);
    char PatternText[sizeOfPattern];
    printf("Enter the pattern : \n");
    scanf("%s", PatternText);

    printf("StringText: %s \n", StringText);
    printf("Patterntext: %s \n", PatternText);

    double total_time;
	clock_t start, end;
	start = clock();
    srand(time(NULL));

    if(sizeOfPattern > sizeOfString)
    {
        printf("Error \n");
        exit(0);
    }

    int i,j = 0;
    int flag = 0;
    int count = 0;
    for(i = 0; i <= (sizeOfString - sizeOfPattern); i++)
    {
        while(flag == 0 && j < sizeOfPattern)
        {
            if(PatternText[j] == StringText[i+j])
            {
                j++;
            }

            else
            {
                flag = 1;
            }
        }

        if(flag == 0)
        {
            printf("Found Pattern between position %d and %d \n",i,i+j-1);
            count++;
        }
        flag = 0;
        j = 0;
    }

    if(count == 0)
    {
        printf("Pattern not found \n");
    }

    end = clock();
	//time count stops 
	total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	//calulate total time
    printf("total time taken: %lf \n", total_time);
}
