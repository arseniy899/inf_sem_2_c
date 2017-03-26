
#include <stdio.h>

void main()
{
    printf("Calculating two numbers like <5*6>\n");
    int a = 0, b= 0;
    float res= 0.0;
    char o = 0;
    scanf("%i%c%i",&a,&o,&b);
    switch(o)
    {
        case '+':
            res = a+b;
        break;
        case '-':
            res = a-b;
        break;
        case '*':
            res = a*b;
        break;
        case '%':
            res = a%b;
        break;
        case '/':
            if(b==0)
                printf("ERROR:dividing on Zero\n");
            else
                res = a/b;
        break;
        case '^':
            res = a;
            for(int i=1;i<b;i++)
                res *= a;
        break;
    }
    printf("=%.2f\n",res);
} 
