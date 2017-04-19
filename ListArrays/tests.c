#include "Array.h"
#include <time.h>
int compArr(byte * a1, byte *a2)
{
	return -(((int)*a1) - ((int)*a2));
}
int main()
{
	struct ArrayElement * arr = NULL, *arr2 = NULL;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int num = rand() % 50;
		add(&arr, (byte *)&num, sizeof(num));
		printf("\narr[%i] = %i;", i, num);
		num = rand() % 50;
		add(&arr2, (byte *)&num, sizeof(num));
		printf("\tarr2[%i] = %i", i, num);
	}
	printf("\nOUTPUT:\n");
	for(int i = 0;i<arraySize(arr); i++)
		printf("\narr[%i] = %i",i,(int)*get(arr,i));

	int num = -3;
	addInd(arr, 1, (byte *)&num, sizeof(char));
	printf("\nADDED -3 aft 1 ind\n");
	for (int i = 0; i<arraySize(arr); i++)
		printf("\narr[%i] = %i", i, (int)*get(arr, i));
	removeLast(arr);
	removeEl(arr, 4);
	int nums = 150;
	set(arr, 2, (byte *)&nums, sizeof(num));
	printf("\nREMOVED last and at 4 ind, set 2 to 150\n");
	for (int i = 0; i<arraySize(arr); i++)
		printf("\narr[%i] = %i", i, (int)*get(arr, i));
	printf("\nLAST ELEM:%i at %i\n", (int)*getLast(arr), arraySize(arr)-1);
	printf("\nJOINED\n");
	join(arr, arr2);
	for (int i = 0; i<arraySize(arr); i++)
		printf("\narr[%i] = %i", i, (int)*get(arr, i));
	sortArray(&arr, &compArr);
	printf("\nSORTED\n");
	for (int i = 0; i<arraySize(arr); i++)
		printf("\narr[%i] = %i", i, (int)*get(arr, i));

	printf("\nCLEARED\n");
	clear(&arr);
	for (int i = 0; i<arraySize(arr); i++)
		printf("\narr[%i] = %i", i, (int)*get(arr, i));
	return 0;
}

