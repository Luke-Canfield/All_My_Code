// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_COUNTCHAR
bool countChar(char * filename, int * counts, int size)
{
  // open a file whose name is filename for reading
  FILE* fp;
  fp = fopen(filename, "r");

  // if fopen fails, return false. Do NOT fclose
  if(fp == NULL) {
	  return false;
  }
  // if fopen succeeds, read every character from the file
  // if a character (call it onechar) is between
  // 0 and size - 1 (inclusive), increase
  // counts[onechar] by one
  // You should *NOT* assume that size is 256
  
  int onechar;
  while((onechar = fgetc(fp)) != EOF) {
	  if(onechar >= 0 && onechar <= (size - 1)) {
		  counts[onechar]++;
	  }
  }

  // remember to call fclose
  fclose(fp);

  // you may assume that counts already initialized to zero
  // size is the size of counts
  // you may assume that counts has enough memory space
  //
  // hint: use fgetc
  // Please read the document of fgetc carefully, in particular
  // when reaching the end of the file
  //
  return true;
}
#endif

#ifdef TEST_PRINTCOUNTS
void printCounts(int * counts, int size)
{
  // print the values in counts in the following format
  // each line has three items:
  // ind, onechar, counts[ind]
  // ind is between 0 and size - 1 (inclusive)
  // onechar is printed if ind is between 'a' and 'z' or
  // 'A' and 'Z'. Otherwise, print space
  // if counts[ind] is zero, do not print
  for(int i = 0; i < size; i++) {
	  if(counts[i] == 0) {
	  }
	  else if((i >= 97 && i <= 122) || (i >= 65 && i <= 90)) {
		  printf("%d, %c, %d\n", i, i, counts[i]);
	  }
	  else {
		  printf("%d, %c, %d\n", i, ' ', counts[i]);
	  }
  }
}
#endif
