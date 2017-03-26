#include <stdio.h>
char*  strncpy(char *t, char * s, int n)
{
   for(int i=0;i<n;i++)
		t[i] =s[i];
   return t;
}
char* strncat(char *t, char * s, int n)
{
	int len = strlen(t);
	for (int i = 0; i < n; i++)
		t[len + i] = s[i];
	return t;
}
int strcmp(char* t, char* s, int n)
{
	while (*t != 0 && *s != 0 && (n--)>0)
	{
		if (*t != *s)
			return *s - *t;
		t++;
		s++;
	}
	return *s - *t;
}
int main()
{
    printf("Overriding default functions.\n");
	char a[] = "Hello, World!!!";
    char b[] = "Hi, Allegro!";
	char c[] = "Tiu than hu!";
	printf("\strncpy=%s", strncpy(b, a, 8));
    printf("\nstrncat=%s", strncat(a, c, 8));
	printf("\nstrcmp=%i", strcmp(a, c, 8));
	return 0;
}
