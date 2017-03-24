#include <stdio.h>
#define FILE_NAME_LENGTH 256

int main(int argc, char*argv[])
{
   char ch, sourceFn[FILE_NAME_LENGTH], targetFn[FILE_NAME_LENGTH];
   FILE *sourceFile, *targetFile;
 
   printf("File copying\nEnter name of file to copy;\n");
   scanf("%s",sourceFn);
 
   sourceFile = fopen(sourceFn, "r");
 
   if( sourceFile == NULL )
   {
      printf("Source file error!\n");
      return 1;
   }
     
   printf("Enter name of target file\n");
   scanf("%s",targetFn);
 
   targetFile = fopen(targetFn, "w");
   
   if( targetFile == NULL )
   {
        fclose(sourceFile);
        printf("Target file error!\n");
        return 2;
   }
   while( ( ch = fgetc(sourceFile) ) != EOF )
      fputc(ch, targetFile);
 
   printf("File copied successfully.\n");
 
   fclose(sourceFile);
   fclose(targetFile);
   return 0; 
}

