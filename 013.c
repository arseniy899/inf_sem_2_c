#include <stdio.h>
#define STR_LENTGH 128
void printLineGist(int n)
{
    
    for(int i=0;i<n;i++)
        printf("=");
}

int main(int argc, char*argv[])
{
    char str[STR_LENTGH] = {0}, tempStr[STR_LENTGH] = { 0 };
    int curSize = 0;
    printf("Popularity of words typed:\n\n");
    scanf("%[^\n]s",&str);
    for(int i=0;i<strlen(str);i++)
    {
		if (str[i] == ' ')
		{
			printLineGist(curSize);
			printf("(%i) \t\t\t%s\n", curSize, tempStr);
			curSize = 0;
		}
		else
		{
			tempStr[curSize++] = str[i];
			tempStr[curSize] = 0;
		}
    }

    printLineGist(curSize);
	printf("(%i) \t\t\t%s\n", curSize, tempStr);
    return 0;
}

