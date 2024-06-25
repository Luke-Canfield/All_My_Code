#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "priority_queue.h"

Node* pq_enqueue(Node** a_head, void* a_value, int (*cmp_fn)(const void*, const void*)) {
	Node* new_node = malloc(sizeof(*new_node));
	*new_node = (Node) { .a_value = a_value, .next = *a_head };
	
	if(*a_head == NULL || cmp_fn == NULL || cmp_fn(a_value, (*a_head) -> a_value) < 0) {
		*a_head = new_node;
	}
	else {
		Node* before_node = *a_head;
		while(before_node -> next != NULL && cmp_fn(a_value, before_node -> next -> a_value) >= 0) {
			before_node = before_node -> next;
		}
		new_node -> next = before_node -> next;
		before_node -> next  = new_node;
	}		
	return new_node;
}

Node* pq_dequeue(Node** a_head) {
	Node* removed_node = *a_head;
	if(*a_head != NULL) {
		*a_head = (*a_head) -> next;
		(removed_node) -> next = NULL;
	}
	return removed_node;
}

Node* stack_push(Node** a_head, void* a_value) {
	return pq_enqueue(a_head, a_value, NULL);
}

Node* stack_pop(Node** a_head) {
	return pq_dequeue(a_head);
}

void destroy_list(Node** a_head, void (*destroy_value_fn)(void*)) {
	Node* old_head;
	while(*a_head != NULL) {
		old_head = stack_pop(a_head);
		destroy_value_fn(old_head -> a_value);
		free(old_head);
	}
}

//#define HUFFMAN_C_V1
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
