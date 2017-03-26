#include <stdio.h>
#include <math.h>
#include <string.h>
 
 
int bin2dec(char * str)
{
    int res = 0;
 
    for(int i=0;i<strlen(str);i++)
    {
        if((str[i]-'0')>0)
            res += pow(2,strlen(str)-1-i)*(str[i]-'0');
    }
    return res;
}
int main(int argc, char*argv[])
{
    char str[33]={0};
    printf("Converting binary string to decimal\n");
    scanf("%s",&str);
    printf("\n0d=%s->0b=%i",str,bin2dec(str));
    return 0;
}