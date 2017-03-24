#include <stdio.h>
#define INT_LENTGH 8
void dec2bin(int *retArr, int dec)
{
	int arr[INT_LENTGH] = { 0 }, rev[INT_LENTGH] = { 0 }, n = 0;
	while (dec > 1)
	{
		arr[n++] = dec % 2;
		arr[n] = 0;
		retArr[n] = 0;
		dec /= 2;
	}
	for (int i = 0; i < INT_LENTGH-1; i++)
		retArr[i] = arr[INT_LENTGH-n -i];
	
}
int rightrot (int x, int n)
{
	int arr[INT_LENTGH] = { 0 };
	dec2bin(arr,x);
	for (int q = INT_LENTGH - 1; q>0; q--)
		printf("%d", arr[INT_LENTGH - q] & 0x1);
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		int m = arr[INT_LENTGH-1];
		for (int q = INT_LENTGH-1; q>0; q--)
		{
			arr[q] = arr[q-1];
			printf("%d", arr[INT_LENTGH -q] & 0x1);
		}
		arr[0] = m;
	}
	printf("\n");
	return bin2dec(arr);
}
int pow(int a, int pow)
{
	if (pow == 0)
		return 1;
	int r = 1;
	for (int i = 0; i<pow; i++)
		r *= a;
	return r;
}
int bin2dec(int * arr)
{
	int res = 0;
	for (int i = 0; i<INT_LENTGH; i++)
		res += pow(2, INT_LENTGH - 1 - i)*arr[i];
	return res;
}

void main()
{
	printf("%i",rightrot(7, 1));
}
