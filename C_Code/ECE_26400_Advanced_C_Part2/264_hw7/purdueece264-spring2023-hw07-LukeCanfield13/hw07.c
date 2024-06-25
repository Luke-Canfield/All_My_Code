// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
	FILE* fp;
	fp = fopen(filename, "r");

	if(fp == NULL) {
		return -1;
	}

	int num_integers = 0;
	int number;

	while(fscanf(fp, "%d", &number) != EOF) {
		num_integers++;
	}
    //fseek(fp, 0, SEEK_SET);	
	fclose(fp);

	return num_integers;
  // count the number of integers in the file
  // Please notice that if a file contains
  // 124 378 -56
  // There are three integers: 124, 378, -56
  // DO NOT count individual character '1', '2', '4' ...
  //
  // If fopen fails, return -1

  // remember to fclose if fopen succeeds
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  // read integers from the file.
  int index = 0;
  FILE* fp;
  fp = fopen(filename, "r");
  if(fp == NULL) {
	  return false;
  }
  else {
	  while(fscanf(fp, "%d",&intArr[index]) != EOF) {
		  index++;
	  }
  }

  // if the number of integers is different from size (too
  // few or too many) return false
  if(size != index) {
	  return false;
  }

  // if everything is fine, fclose and return true
  fclose(fp);
  return true;
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
  // needed by qsort
  //
  // return an integer less than, equal to, or greater than zero if
  // the first argument is considered to be respectively less than,
  // equal to, or greater than the second.
  return ( *(int*)p1 - *(int*)p2 );

}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  FILE* fp;
  fp = fopen(filename, "w");
  if(fp == NULL) {
	  return false;
  }
  // write integers to the file.
  // one integer per line
  else {
	  for(int i = 0; i < size; i++) {
		  fprintf(fp, "%d\n", intArr[i]);
	  }
  }

  // fclose and return true
  fclose(fp);
  return true;
}
#endif
