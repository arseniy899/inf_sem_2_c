#include <stdio.h>

int main(int argc, char*argv[])
{
    char str[128] = {0}, max = 0;
    printf("Finding the biggest ASCII char number. Enter the line:\n");
    scanf("%[^\n]s",&str);
    printf("chr-code");
    for(int i=0;i<strlen(str);i++)
    {
        printf("\n%c  -   %i",str[i],str[i]);
        if(max < str[i])
            max = str[i];
    }
    printf("\nMax char code: %i, %c",max,max);
    return 0;
}

