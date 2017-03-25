#include <stdio.h>
#define INT_LENTGH 8
int rightrot(int a, int n)
{
	for (int i = 0; i<n; i++)
	{
		int l = a & 1;
		l = l<<sizeof(int);
		a = a>>1;
		a = a | l;
	}
	return a;
}

void main()
{
	printf("rightrot=%i",rightrot(4, 1));
	
}
