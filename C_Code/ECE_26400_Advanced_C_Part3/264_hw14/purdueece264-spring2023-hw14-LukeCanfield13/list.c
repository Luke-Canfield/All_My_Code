// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#ifdef TEST_READLIST
// read line by line from the input file
// each line shorter than WORDLENGTH (including '\n' and '\0')
// arithlist should have memory to store head and tail
// If arithlist is NULL, return false
// If fopen fails, return false
// If a line is too long,
//    free memory of the list
//    fclose
//    return false
// If everything is fine
//    fclose
//    arithlist points to the head and tail of the list
//    return true
bool readList(char * filename, List * arithlist) {
    FILE *fp;
	fp = fopen(filename, "r");
	char word[WORDLENGTH];

	if(fp == NULL) {
		return false;
	}
	while(fgets(word, WORDLENGTH, fp) != NULL) {
		if(strchr(word, '\n')) {
			addNode(arithlist, word);
		}
		else {
			free(arithlist);
			fclose(fp);
			return false;
		}
	}
	fclose(fp);
	return true;
}
#endif

#ifdef TEST_DELETELIST
// If arithlist is NULL, do nothing
// release the memory of every node in the list
// release the memory of the list
void deleteList(List * arithlist) {
	if(arithlist != NULL) {
		ListNode *curr = arithlist->head;
		ListNode *next = NULL;
		while(curr != NULL) {
			next = curr->next;
			free(curr);
			curr = next;
		}
		free(arithlist);
	}
}

#endif

#ifdef TEST_ADDNODE
// Input: 
// arithlist stores the addresses of head and tail
// If arithlist is NULL, do nothing
// word is the word to be added
//
// Output:
// a ListNode is added to the end (become tail)
//
// allocate memory for a new ListNode
// copy word to the word attribute of the new ListNode
// insert the ListNode to the list
void addNode(List * arithlist, char * word) {
	if(arithlist == NULL) {
		return;
	}

	ListNode *new_node = NULL;
	new_node = malloc(sizeof(ListNode));
	strcpy(new_node->word, word);
	new_node->next = NULL;
	new_node->prev = arithlist->tail;

	if(arithlist->head == NULL) {
		arithlist->head = new_node;
	}
	else {
		(arithlist->tail)->next = new_node;
	}
	arithlist->tail = new_node;
}

#endif

#ifdef TEST_DELETENODE
//  Input:
// arithlist stores the addresses of head and tail
// If arithlist is NULL, return false
// If the list is empty (head and tail are NULL), return false
// ln is the node to be deleted
// If ln is not in the list, return false
// 
// Output:
// arithlist stores the addresses of head and tail
//   after ln is deleted
// return true.
//
// Be careful about delete the first or the last node
bool deleteNode(List * arithlist, ListNode * ln) {
    if(arithlist == NULL) {
		return false;
	}
	if((arithlist->head == NULL) && (arithlist->tail == NULL)) {
		return false;
	}
	
	ListNode *ind = arithlist->head;

	while(ind != NULL) {
		if(ind == ln) {
			if(arithlist->head == ln) {
				arithlist->head = ln->next;
				(ln->next)->prev = NULL;
			}
			else if(arithlist->tail == ln) {
				arithlist->tail = ln->prev;
				(ln->prev)->prev = NULL;
			}
			else {
				(ln->prev)->next = ln->next;
				(ln->next)->prev = ln->prev;
			}
			free(ln);
			break;
		}
		ind = ind->next;
	}
	return true;
}
#endif

