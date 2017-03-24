#include <stdio.h>

int main(int argc, char*argv[])
{
    char str[33]={0};
    printf("Converting binary string to decimal\n");
    scanf("%s",&str);
    printf("\n0d=%s->0b=%i",str,bin2dec(str));
    return 0;
}
int bin2dec(char * str)
{
    int res = 0;

    for(int i=0;i<strlen(str);i++)
    {
        
        if((str[i]-'0')>0)
            res += pow(2,strlen(str)-1-i)*(str[i]-'0');
        printf("\n%i*%i",pow(2,strlen(str)-1-i),(str[i]-'0'));
    }
    return res;
}
int pow(int a, int pow)
{
    if(pow == 0)
        return 1;
    int r =1;
    for(int i=0;i<pow;i++)
        r*=a;
    return r;
}
