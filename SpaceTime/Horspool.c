#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int* ShiftTable(char PatternText[], int sizeOfPattern)
{
    int* Table = malloc (sizeof(int) * 128);

    int i,j;

    for(i = 0; i < 128; i++)
    {
        Table[i] = sizeOfPattern;
    }

    for(j = 0; j < sizeOfPattern - 1; j++)
    {
        Table[PatternText[j]] = sizeOfPattern - 1 - j;
    }

    return Table;
}

int HorspoolMatching(char PatternText[], int sizeOfPattern, char StringText[], int sizeOfString)
{
    int* Table = ShiftTable(PatternText, sizeOfPattern);
    int i = sizeOfPattern-1;
    int k;
    while(i < sizeOfString)
    {
        k = 0;
        while(k <= sizeOfPattern - 1 && (PatternText[sizeOfPattern - 1 - k] == StringText[i - k]))
        {
            k = k + 1;
        }

        if(k == sizeOfPattern)
        {
            return (i - sizeOfPattern + 1);
        }

        else
        {
            i = i + Table[StringText[i]];
        }   
    }

    return -1;
}

int main()
{
    int sizeOfString; int sizeOfPattern;
    int AlphabetSize;
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
    //printf("Enter the size of the alphabet: \n");
    //scanf("%d", &AlphabetSize);

    double total_time;
	clock_t start, end;
	start = clock();
    srand(time(NULL));

    printf("StringText: %s \n", StringText);
    printf("Patterntext: %s \n", PatternText);

    int position = HorspoolMatching(PatternText, sizeOfPattern, StringText, sizeOfString);

    if(position == -1)
    {
        printf("No matches\n");
    }

    else
    {
        printf("Found at position %d\n",position);
    }
    
    end = clock();
	//time count stops 
	total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	//calulate total time
    printf("total time taken: %lf \n", total_time);
}
