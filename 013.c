#include <stdio.h>
void printLineGist(int n)
{
    printf(" ");
    for(int i=0;i<n;i++)
        printf("=");
}

int main(int argc, char*argv[])
{
    char str[128] = {0};
    int curSize = 0;
    printf("Popularity of words typed:\n\n");
    scanf("%[^\n]s",&str);
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i] ==' ')
        {
            printLineGist(curSize);
            printf(" %i\n",curSize);
            curSize=0;
        }
        else
        {
            printf("%c",str[i]);
            curSize++;
        }
    }
    printLineGist(curSize);
    printf(" %i\n",curSize);
    return 0;
}

