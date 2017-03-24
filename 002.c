#include <stdio.h>
int day = 25, month = 7;
int main(int argc, char*argv[])
{
	printf("Before:day=%i,month=%i\r\n",day,month);
	month = month * 31 + day;
	day = month /31;
	month %=31;
	printf("After:day=%i,month=%i\r\n",day,month); 
	return 0;
}
