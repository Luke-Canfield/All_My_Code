#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "stack.h"

bool is_empty(Stack const* a_stack) {
	return (a_stack -> top == NULL);
}

Stack create_empty_stack(size_t max_block_size_bytes) {
	assert(max_block_size_bytes >= MIN_NODE_BLOCK_SIZE_BYTES);
	BlockNode dummy_node;
	size_t num_bytes = sizeof(dummy_node.values[0]);
	Stack stack = (Stack) {.top = NULL, .num_values_per_node = ((max_block_size_bytes - MIN_NODE_BLOCK_SIZE_BYTES) / num_bytes + 1)};
	return stack;
}

void push(Stack* a_stack, int value) {
	BlockNode dummy_node;
	if(a_stack->top == NULL || a_stack->top->num_empty_slots == 0) {
		BlockNode* new_node = malloc(sizeof(*new_node) + sizeof(dummy_node.values[0]) * a_stack->num_values_per_node - 1);
		*new_node = (BlockNode) {.next = a_stack->top, .num_empty_slots = a_stack->num_values_per_node};
		a_stack->top = new_node;
	}
	a_stack->top->values[a_stack->num_values_per_node - a_stack->top->num_empty_slots] = value;
	a_stack->top->num_empty_slots--;
	assert(!is_empty(a_stack));  // Post-condition: stack must not be empty when function exits
}

int pop(Stack* a_stack) {
	assert(!is_empty(a_stack));  // Pre-condition: stack must not be empty when function begins
	int	popped_val = a_stack->top->values[a_stack->num_values_per_node - a_stack->top->num_empty_slots - 1];
	a_stack->top->num_empty_slots++;

	if(a_stack->top->num_empty_slots == a_stack->num_values_per_node) {
		BlockNode* temp = a_stack->top;
		a_stack->top = a_stack->top->next;
		free(temp);
	}
	return popped_val;  
}

void empty(Stack* a_stack) {
	while(a_stack->top != NULL) {
		BlockNode* temp = a_stack->top;
		a_stack->top = a_stack->top->next;
		free(temp);
	}
	assert(is_empty(a_stack));  // Post-condition: stack must be empty when function exits
}

int peek_value_from_top_node(Stack const* a_stack) {
	assert(!is_empty(a_stack));  // Pre-condition: stack must not be empty
	return a_stack->top->values[a_stack->num_values_per_node - a_stack->top->num_empty_slots - 1]; 
}


#define STACK_C_VERSION_2  // Do not delete or modify this line.  It helps us track any updates.
/* vim: set tabstop=4 shiftwi:dth=4 fileencoding=utf-8 noexpandtab: */
