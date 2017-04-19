#include "Array.h"
ArrayElement *getLastEl(const ArrayElement *arrayC);
int arraySize(const ArrayElement *arrayC)
{
	 if (!arrayC)
		 return 0;
	int ret = 0;
	
	for (ArrayElement *cur = arrayC; cur; cur = cur->linkToNext, ++ret);
	return ret;
}
byte *get(const ArrayElement *arrayC, int i)
{
	if (i > arraySize(arrayC))
		return NULL;
	ArrayElement *cur = arrayC;
	while (cur->linkToNext && (i--) > 0)
		cur = cur->linkToNext;
	return cur->container;
}
ArrayElement *getEl(const ArrayElement *arrayC, int i)
{
	if (i > arraySize(arrayC))
		return NULL;
	ArrayElement *cur = arrayC;
	while (cur->linkToNext && (i--) > 0)
		cur = cur->linkToNext;
	return cur;
}

void add(ArrayElement **arrayC, const byte * cont, const size_t size)
{
	if (*arrayC == NULL)
	{
		*arrayC = malloc(sizeof(ArrayElement));
		(*arrayC)->container = malloc(size);
		memcpy((*arrayC)->container, cont, size);
		(*arrayC)->linkToNext = NULL;
		(*arrayC)->linkToPrev = NULL;
	}
	else
	{
		ArrayElement *newEl = malloc(sizeof(ArrayElement)), *prev = getLastEl(*arrayC);
		newEl->container = malloc(size);
		memcpy(newEl->container, cont, size);
		
		newEl->linkToPrev = prev;
		newEl->linkToNext = NULL;
		prev->linkToNext = newEl;
		
	}
}
int addInd(const ArrayElement *arrayC, int i,const byte * cont, const size_t size)
{
	if (i < 0 || i > arraySize(arrayC))
		return 0;
	if (i == 0)
		add(arrayC, cont, size);
	else
	{
		ArrayElement *prev = getEl(arrayC, i), *next = prev->linkToNext;
		ArrayElement *newEl = malloc(sizeof(ArrayElement));
		newEl->container = malloc(size);
		memcpy(newEl->container, cont, size);
		newEl->linkToPrev = prev;
		newEl->linkToNext = next;
		prev->linkToNext = newEl;
		next->linkToPrev = newEl;
	}
	return i;
}
void set(const ArrayElement *arrayC, int i, const byte * cont, const size_t size)
{
	if (i < 0 || i > arraySize(arrayC))
		return;
	ArrayElement *toSet = getEl(arrayC, i);
	toSet->container = cont;
}
void removeEl(const ArrayElement *arrayC, int i)
{
	if (i < 0 || i > arraySize(arrayC))
		return;
	ArrayElement *toRemove = getEl(arrayC, i), *prev = toRemove->linkToPrev, *next = toRemove->linkToNext;
	if (toRemove->linkToNext == NULL)
		prev->linkToNext = NULL;
	else
	{
		prev->linkToNext = next;
		next->linkToPrev = prev;
		free(toRemove);
	}
	
}

void removeLast(const ArrayElement *arrayC)
{
	ArrayElement *toRemove = getLastEl(arrayC), *prev = toRemove->linkToPrev;
	if (toRemove != NULL)
	{
		prev->linkToNext = NULL;
		free(toRemove);
	}
	
}
void clear(ArrayElement **arrayC)
{
	ArrayElement *cur = getLastEl(*arrayC);
	while (cur)
	{
		cur = getLastEl(*arrayC);
		if(cur)
			free(cur);
		cur = NULL;
	}
	free(*arrayC);
	*arrayC = NULL;
}
ArrayElement *getLastEl(const ArrayElement *arrayC)
{
	if (arrayC == NULL)
		return NULL;
	ArrayElement *cur = arrayC;
	while (cur->linkToNext)
		cur = cur->linkToNext;
	return cur;
}
byte *getLast(const ArrayElement *arrayC)
{
	if (arrayC == NULL)
		return NULL;
	ArrayElement *cur = arrayC;
	while (cur->linkToNext)
		cur = cur->linkToNext;
	return cur->container;
}
ArrayElement *join(ArrayElement *firstArray, ArrayElement *secArray)
{
	ArrayElement *firstArrayLast = getLastEl(firstArray);
	firstArrayLast->linkToNext = secArray;
	secArray->linkToPrev = firstArrayLast;
	return firstArray;
}
void sortArray(ArrayElement **arrayC, int(*compare)(byte *, byte *))
{
	for (int i = 0; i < arraySize(*arrayC); i++)
	{
		for (int q = 0; q < arraySize(*arrayC) - 1; q++)
		{
			ArrayElement *a1 = getEl(*arrayC, i), *a2 = getEl(*arrayC, q);
			if (compare(a1->container, a2->container) < 0)
			{
				byte *newT = a1->container;
				a1->container = a2->container;
				a2->container = newT;
			}
		}
	}
}