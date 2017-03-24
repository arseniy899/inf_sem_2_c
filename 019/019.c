#include <stdio.h>
#define FILE_NAME_LENGTH 256

void copyFile(char* sourceFn, char* targetFn)
{
	char ch;
	FILE *sourceFile = fopen(sourceFn, "r"), *targetFile = fopen(targetFn, "w");
	if (sourceFile == NULL)
	{
		printf("Source file error!\n");
		return 1;
	}
	if (targetFile == NULL)
	{
		fclose(sourceFile);
		printf("Target file error!\n");
		return 2;
	}
	while ((ch = fgetc(sourceFile)) != EOF)
		fputc(ch, targetFile);

	printf("File copied successfully.\n");

	fclose(sourceFile);
	fclose(targetFile);
}
void copyFileWitOComm(char* sourceFn, char* tempFileName)
{
	char ch = 0, prevChr = 0;
	FILE *sourceFile = fopen(sourceFn, "r"), *targetFile = fopen(tempFileName, "w");
	if (sourceFile == NULL)
	{
		printf("Source file error!\n");
		return 1;
	}
	if (targetFile == NULL)
	{
		fclose(sourceFile);
		printf("Temp file error!\n");
		return 2;
	}
	int isMultiline = 0, isSingleLine = 0, isLiteral = 0, isNextChrStlComm = 0;
	while ((ch = fgetc(sourceFile)) != EOF)
	{
		switch (ch)
		{
			case '\"':
				isLiteral = (isLiteral + 1) % 2;
			break;
			case '*':
				if (prevChr == '/' && !isLiteral)
					isMultiline = 1;
			break;
			case '/':
				if (prevChr == '*' && !isLiteral)
				{
					if (!isMultiline)
						printf("ERROR: multiline comment found ending, but no begining!\n");
					else
						isMultiline = 0;
					isNextChrStlComm+=2;
				}
				else if (prevChr == '/' && !isLiteral)
					isSingleLine = 1;
			break;
			case '\n':
				if (isSingleLine)
					isNextChrStlComm++;
				isSingleLine = 0;
			break;
		}
		if(!isMultiline && !isSingleLine && prevChr != 0 && (isNextChrStlComm)==0)
			fputc(prevChr, targetFile);
		else if(isNextChrStlComm>0)
			isNextChrStlComm--;
		prevChr = ch;
	}
	if (!isMultiline && !isSingleLine && prevChr != 0 && isNextChrStlComm>0)
		fputc(prevChr, targetFile);
	printf("Temp file copied successfully.\n");
	if (isMultiline)
		printf("ERROR: multiline comment wasn't closed!\n");
	fclose(sourceFile);
	fclose(targetFile);
	copyFile(tempFileName, sourceFn);
	if (!remove(tempFileName))
		printf("Temp file deleted successfully\n");
	else
		printf("ERROR:: unable to delete temp file\n");
	
}
int main(int argc, char*argv[])
{
	char ch, sourceFn[FILE_NAME_LENGTH];
	printf("File decomment\nEnter name of source file\n");
	scanf("%s", sourceFn);
	copyFileWitOComm(sourceFn, "tempSource.c");
	return 0; 
}

