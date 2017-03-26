#include <stdio.h>
#define STR_LENGTH 256
char* removeDobChr(char * str)
{
	char newStr[STR_LENGTH] = { 0 };
    int mask [STR_LENGTH];
    int strL = strlen(str);
    for(int i=0;i<strL-1;i++)
    {
        if(str[i] == str[i+1])
            mask[i+1]=1;
        else 
            mask[i+1]=0;
        newStr[i]=0;
    }
    //printf("\nstr=%s",str);
    int newSize = 0;
    for(int i=0;i<strL;i++)
    {
       // printf("\n%c %i",str[i],str[i]);
        if(mask[i]==0)
        {
            newStr[newSize]=str[i];
            newSize++;
        }
    }
    //printf("\nstrL=%i,newSize=%i,newStr=%s",strL,newSize,newStr);
    if(strL+1< newSize)
        return removeDobChr(newStr);
	else
	{
		strcpy(str,newStr);
		return str;
	}
}
int main(int argc, char*argv[])
{
    char str [STR_LENGTH] = {0};
    printf("Deleting two similar chars nearby\n");
    scanf("%[^\n]s",&str);
    printf("\nstr=%s",removeDobChr(str));
	return 0;
}
