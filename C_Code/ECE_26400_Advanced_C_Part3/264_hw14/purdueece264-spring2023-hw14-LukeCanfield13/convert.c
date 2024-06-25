// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "list.h"
#include "convert.h"

// DO NOT MODIFY FROM HERE --->>>
const int Operations[] = {'+', '-', '*', '(', ')'};

// return -1 if the word is not an operator
// return 0 if the word contains '+'
//        1                      '-'
//        2                      '*'
//        3                      '('
//        4                      ')'
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
// *** You MUST modify the convert function
// ***
#ifdef TEST_CONVERT

int isParenthesis(char c) {
	return c == '(' || c == ')';
}

int precedence(char c) {
	switch (c) {
		case '+':
	    case '-':
			return 1;
		case '*':
			return 2;
		default:
			return 0;
	}
}

void push(char *stack[], int *top, char data) {
	stack[++(*top)] = (char*) malloc(sizeof(char));
	*(stack[*top]) = data;
}

char pop(char *stack[], int *top) {
	if(*top < 0) {
		printf("Error stack is empty\n");
	}
	char data = *(stack[*top]);
	free(stack[(*top)--]);
	return data;
}

bool convert(List * arithlist) {
  if (arithlist == NULL)
    {
      return true;
    }
  if ((arithlist -> head) == NULL)
    {
      return true;
    }
  return true;

  char *stack[WORDLENGTH];
  int top = -1;
  ListNode *curr = arithlist->head;

  while(curr != NULL) {
	  char *data = curr->word;
	  if(!isOperator(data) && !isParenthesis(*data)) {
		  printf("%s ", data); // if word is number print it
	  }
	  else if(isOperator(data)) {
		  while(top >= 0 && isOperator(stack[top]) && precedence(*stack[top]) >= precedence(*data)) {
			  printf("%d ", pop(stack, &top)); //when word is operator pop operators from stack with >= precedence
		  }
		  push(stack, &top, *data);
	  }
	  else if(*data == '(') {
		  push(stack, &top, *data); //push to stack
	  }
	  else if(*data == ')') {
		  while(top >= 0 && *stack[top] != '(') {
			  printf("%d ", pop(stack, &top)); //pop operators from stack until open parenthesis is found
		  }
		  pop(stack, &top);
	  }
	  curr = curr->next;
  }
  while(top >= 0) {
	  printf("%d ", pop(stack, &top)); //pop any remaining operators
  }
  printf("\n");
}

#endif
