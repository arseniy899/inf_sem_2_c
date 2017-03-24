#include <stdio.h>
int fib(int prev, int cur, int count, int max)
{  
    if(count==1)
        printf("1 1 ");  
    printf("%i ",(prev+cur));
    if(count<max)
    {
        int num = fib(cur, (prev+cur),count+1,max);
        //printf("%i ",num);
     }
    
}

void main()
{
    printf("Finding Fibonachi numbers of given number N\n");
    int n = 0;
    scanf("%i",&n);
    fib(1,1,1,n);
}
