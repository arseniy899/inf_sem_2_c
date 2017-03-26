#include <stdio.h>
int fib(int prev, int cur, int count, int max)
{  
	if (max == 1)
		printf("1 ");
	else
	{
		if (count == 1)
		{
			printf("1 1 ");
			max -= 1;
		}
		else 
		printf("%i ", (prev + cur));
		if (count < max)
			fib(cur, (prev + cur), count + 1, max);
	}
}

void main()
{
    printf("Finding Fibonachi numbers of given number N\n");
    int n = 0;
    scanf("%i",&n);
    fib(1,1,1,n);
}