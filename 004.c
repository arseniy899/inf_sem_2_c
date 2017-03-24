#include <stdio.h>
#define SWAP(T,x,y) {T SWAP = x; x= y; y = SWAP;}
int main(int argc, char*argv[])
{
	int x=10, y=20;
	printf("Before:x=%i,y=%i\r\n",x,y);
	SWAP(int,x,y);
	printf("After:x=%i,y=%i\r\n",x,y);
	char a = 'a', b = 'b';
	printf("Before:a=%c,b=%c\r\n",a,b);
	SWAP(char,a,b);
	printf("After:a=%c,b=%c\r\n",a,b);
	return 0; 
}

