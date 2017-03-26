#include <stdio.h>
#define FILE_NAME_LENGTH 256
#define STRING_LENGTH 64
void xorInvert(char *key, char *data)
{
	printf("%s\n", key);
	for (int i = 0; i < strlen(data)-1; i++)
	{
		printf("%c",data[i]);
		data[i] ^= key[i % strlen(key)];
		printf("->%c,%i,%c\n", data[i],(i % strlen(key)), key[i % strlen(key)]);
	}
}
void readSrcFile(char* str, char* sourceFn)
{
	FILE *sourceFile = fopen(sourceFn, "r");
	if (sourceFile == NULL)
	{
		printf("Source file error!\n");
		return 1;
	}
	int n = 0;
	while ((str[n++] = fgetc(sourceFile)) != EOF);
	fclose(sourceFile);
	
}
void wirteFile(char * targetFn, char* str)
{
	FILE *targetFile = fopen(targetFn, "w");
	targetFile ;

	if (targetFile == NULL)
	{
		printf("Target file error!\n");
		return 2;
	}
	for (int i = 0; i < strlen(str); i++)
		fputc(str[i], targetFile);

	printf("Output gile written successfully.\n");
	fclose(targetFile);
}
int main(int argc, char*argv[])
{
	char * key[STRING_LENGTH] = { 0 }, *str[STRING_LENGTH] = { 0 }, *sourceFn[FILE_NAME_LENGTH];
	printf("XOR encryptor/decryptor\nEnter name of source file:\n");
	scanf("%s", &sourceFn);
	readSrcFile(str, sourceFn);
	printf("Enter KEY:\n");
	scanf("%s", key);
	printf("\nReeded from source:\n%s\n", str);
	xorInvert(key, str);
	printf("Your data output:\n%s\nOutput to file?\nType 1 if so:\n",str);
	int outFile = 0;
	scanf("%i", &outFile);
	if (outFile == 1)
	{
		printf("\nEnter name of destination file:\n");
		scanf("%s", &sourceFn);
		wirteFile(sourceFn, str);
	}
	return 0; 
}
 