// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw08.h"


#ifdef TEST_COUNTVECTOR
int countVector(char * filename)
{
  // count the number of vectors in the file and return the number
  // The input is a binary file. You must use fread.
  // You must not use fscanf(, "%d", ) 
  //
  // If fopen fails, return -1
  //
  //
  // For the mode of fopen, you may use "r" without b
  FILE* fp;
  fp = fopen(filename, "r");
  if(fp == NULL) {
	  return -1;
  }

  int num_vectors = 0;
  Vector buffer;

  while(fread(&buffer, sizeof(Vector), 1, fp) == 1) {
	  num_vectors++;
  }
  
  fclose(fp);

  return num_vectors;

}
#endif

#ifdef TEST_READVECTOR
bool readVector(char* filename, Vector * vecArr, int size)
{
  // if fopen fails, return false
  FILE* fp;
  fp = fopen(filename, "r");
  if(fp == NULL) {
	  return false;
  }
  // read Vectors from the file.
  int count_Integers;
  count_Integers = fread(&vecArr[0], sizeof(Vector), size, fp);
  
  // if the number of integers is different from size (too
  // few or too many) return false
  if(count_Integers != size) {
	  return false;
  }
  // if everything is fine, fclose and return true
  fclose(fp);
  return true;
}
#endif

#ifdef TEST_COMPAREVECTOR
int compareVector(const void *p1, const void *p2)
{
  Vector *one = (Vector*)p1;
  Vector *two = (Vector*)p2;

  // compare the x attribute first
  // If the first vector's x is less than the second vector's x
  // return -1
  if(one->x < two->x) {
	  return -1;
  }

  // If the first vector's x is greater than the second vector's x
  // return 1
  else if(one->x > two->x) {
	  return 1;
  }
  
  // If the two vectors' x is the same, compare the y attribute
  //
  // If the first vector's y is less than the second vector's y
  // return -1
  else if(one->x == two->x) {
	  if(one->y < two->y) {
		  return -1;
	  }
	  else if(one->y > two->y) {
		  return 1;
	  }
	  else if(one->y == two->y) {
		  if(one->z < two->z) {
			  return -1;
		  }
		  else if(one->z > two->z) {
			  return 1;
		  }
		  else if(one->z == two->z) {
			  return 0;
		  }
	  }
  }
  
  // If the first vector's y is greater than the second vector's y
  // return 1
  // If the two vectors' y is the same, compare the z attribute
  //
  // If the first vector's z is less than the second vector's z
  // return -1
  // If the first vector's z is greater than the second vector's z
  // return 1
  // If the two vectors' x, y, z are the same (pairwise), return 0
  return 0;
}
#endif

#ifdef TEST_WRITEVECTOR
bool writeVector(char* filename, Vector * vecArr, int size)
{
  // if fopen fails, return false
  FILE* fp;
  fp = fopen(filename, "w");
  if(fp == NULL) {
	  return false;
  }
  // write the array to file using fwrite
  int written_Ints;
  written_Ints = fwrite(&vecArr[0], sizeof(Vector), size, fp);
  // need to check how many have been written
  // if not all are written, fclose and return false
  if(written_Ints != size) {
  	fclose(fp);
	return false;
  }
  // fclose and return true
  fclose(fp);
  return true;
}
#endif

// This function is provided to you. No need to change
void printVector(Vector * vecArr, int size)
{
  int ind = 0;
  for (ind = 0; ind < size; ind ++)
    {
      printf("%6d %6d %6d\n",
	     vecArr[ind].x, vecArr[ind].y, vecArr[ind].z);
    }
}
