#include <stdio.h>
#define FILE_NAME_LENGTH 256
/*
This file is needed only for checking how programm for 18 problem works.
Compile and run 019.c, enter 019_ex.c and this and other comments will dissapear
*/
int main(int argc, char*argv[])
{
   char ch, sourceFn[FILE_NAME_LENGTH], targetFn[FILE_NAME_LENGTH];
   FILE *sourceFile, *targetFile;
 
   printf("File copying\nEnter name of file to copy;\n");
   scanf("%s",sourceFn);
//this comment will dissapear
   sourceFile = fopen(sourceFn, "r");
 
   if( sourceFile == NULL )
   {
      printf("Source file error!\n");
      return 1;
   }
//and this also this comment will dissapear
     /*some sinle lines.*/
   printf("Enter name of target file\n");
   scanf("%s",targetFn);
 
   targetFile = fopen(targetFn, "w");//Oh, damn it! In next line is unstarted comment
   */
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
//and there in next line comment which was'nt closedir
/*