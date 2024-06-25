// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_ADDFILE
bool addFile(char * filename, int * sum)
{
  // You cannot assume * sum is zero. Thus, * sum needs to be set 0
  *sum = 0;

  // open a file whose name is filename for reading
  FILE* fp;
  fp = fopen(filename, "r");

  // if fopen fails, return false. Do NOT fclose
  if(fp == NULL) {
	  return false;
  }

  // if fopen succeeds, read integers using fscan (do not use fgetc)
  // * sum stores the result of adding all numbers from the file
  // When no more numbers can be read, fclose, return true
  int number;
  while(fscanf(fp, "%d", &number) != EOF) {
	  *sum += number;
  }
  fclose(fp);

  return true;
}
#endif


#ifdef TEST_WRITESUM
bool writeSum(char * filename, int sum)
{
  // open a file whose name is filename for writing
  FILE* fp;
  fp = fopen(filename, "w");

  // if fopen succeeds, write sum as an integer using fprintf
  if(fp != NULL) {
	  fprintf(fp,"%d\n",sum);
  }

  // fprintf should use one newline '\n'
  // fclose, return true
  fclose(fp);

  return true;
}
#endif
