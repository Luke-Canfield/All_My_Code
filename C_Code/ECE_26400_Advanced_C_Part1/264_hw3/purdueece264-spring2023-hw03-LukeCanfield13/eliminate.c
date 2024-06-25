// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
  // initialize all elements
  for(int i = 0; i < n; i++) {
	  arr[i] = 0;
  }

  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked

  int stop = 0; //indicates when to stop loop
  int index = 0; //array index
  int count = 1; //variable to count to k

  while(stop != (n - 1)) {
  	if(index > (n - 1)) {
		index = 0;
	}
  	if(count == k) {
  		if(arr[index] == 0) {
			printf("%d\n",index);
			arr[index] = 1;
			count = 1;
			index = index + 1;
			stop++;
		}
		else {
			while(arr[index] == 1) {
				index = index + 1;
				if(index > (n - 1)) {
					index = 0;
				}
			}
			printf("%d\n",index);
			arr[index] = 1;
			count = 1;
			index = index + 1;
			stop++;
		}
   }
   else {
	  if(arr[index] != 1) {
		  count++;
	  }
	  index++;
   }
  }

  // print the last one
  for(int j = 0; j < n; j++) {
	  if(arr[j] == 0) {
		  printf("%d\n", j);
	  }
  }

  // release the memory of the array
  free (arr);
}
#endif
