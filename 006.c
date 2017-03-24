
#include <stdio.h>

void main()
{
    printf("Input number to get factorial of it:\n");
    int n = 0;
    scanf("%i",&n);
    printf("Factorial:%i\n",fact(n));

}
int fact(int n)
{
    if(n<0)
        return -1;//Error: Impossible to find factorial of negative number
    else if(n<=1)
        return 1;//Factorial of 0 is always 1
    else
        return n*fact(n-1);
}