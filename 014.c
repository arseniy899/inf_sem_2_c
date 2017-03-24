#include <stdio.h>
#define STR_LENGTH 256
char * reverse(char *str)
{
    char  rev[STR_LENGTH+1];
    for(int i=0;i<strlen(str);i++)
    {
        rev[i]= str[strlen(str)-i-1];
        rev[i+1]=0;
        
    }
    printf("\n%s\n",rev);
    return rev;
}
int main(int argc, char*argv[])
{
    char str[STR_LENGTH];
    
    printf("Reverse string:\n\n");
    scanf("%[^\n]s",&str);
    printf("\nReverse:%s\n",reverse(str));
    return 0;
}

