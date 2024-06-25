// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "calculate.h"

// DO NOT MODIFY FROM HERE --->>>
const int Operations[] = {'+', '-', '*'};

// return -1 if the word is not an operator
// return 0 if the word contains '+'
// return 1 if the word contains '-'
// ...
int isOperator(char * word)
{
  int ind;
  int numop = sizeof(Operations) / sizeof(int);
  for (ind = 0; ind < numop; ind ++)
    {
    char *loc = strchr(word, Operations[ind]);
    if (loc != NULL && !isdigit(loc[1]))
	{
	  return ind;
	}
    }
  return -1;
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the calculate function
// ***
#ifdef TEST_CALCULATE
// if arithlist is NULL, return true
// if arithlist -> head is NULL, return true
// if the input list is invalid, return false
bool calculate(List * arithlist)
{
  if (arithlist == NULL)
    {
      return true;
    }
  if ((arithlist -> head) == NULL)
    {
      return true;
    }
  // go through the list until there is only node in the list
  // find the next operator
  // If no operator can be found, return false
  // If an operator is found, find the two previous nodes as operands
  // If cannot find previous two operands, return false
  // If two operands can be found, perform the arithmetic operation
  // Be careful, subtraction is no commutative: 4 2 - means 4 - 2,
  //    not 2 - 4
  // After the operation,
  //     put the result back to the list
  //     remove the two nodes used to store the two operands
  // After going through the entire list and performing the operations,
  //     the list should have exactly one node left. If this is not
  //     true, return false
  // If the input is valud, return true
  ListNode *node = arithlist->head;
  int x;
  int y;
  int result;
  int op;

  while(node != NULL) {
	  op = isOperator(node->word);
	  if(op != -1) {
		  if((node->prev == NULL) || ((node->prev)->prev == NULL)) {
			  return false;
		  }
		  x = (int)strtol(node->prev->prev->word, NULL, 10);
		  y = (int)strtol(node->prev->word, NULL, 10);
		  if(op == 0) {
			  result = x + y;
			  sprintf(node->word, "%d\n", result);
		  }
		  else if(op == 1) {
			  result = x - y;
			  sprintf(node->word, "%d\n", result);
		  }
		  else if(op == 2) {
			  result = x * y;
			  sprintf(node->word, "%d\n", result);
		  }

		  deleteNode(arithlist, node->prev);
		  deleteNode(arithlist, node->prev);
	  }
	  node = node->next;
  }
  
  // if more than one node left, return false
  // if the remaining node is an operator, return false
  // if everything is OK, return true
  if(arithlist->head != arithlist->tail) {
	  return false;
  }
  return true;
}
#endif
