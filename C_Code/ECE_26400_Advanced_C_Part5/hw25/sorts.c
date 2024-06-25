#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "sorts.h"
#include "clog.h"
/*
void _insert(int value, BSTNode** a_root) {
	if(*a_root != NULL) {
		BSTNode* new_node = malloc(sizeof(*new_node));
		*new_node = (BSTNode) { .value = value, .left = NULL, .right = NULL };
		*a_root = new_node;
	}
	else if(value < (*a_root) -> value) {
		_insert(value, &((*a_root) -> left));
	}
	else {
		_insert(value, &((*a_root) -> right));
	}
}

void _destroy(BSTNode** a_root) {
	if(*a_root != NULL) {
		free((*a_root) -> left);
		free((*a_root) -> right);
		free(*a_root);
	}
	*a_root = NULL;
}

void _fill_array_from_bst(BSTNode* a_root, int** array) {
	if(a_root != NULL) {
		_fill_array_from_bst((a_root) -> left, &(*array));
		**array = a_root -> value;
		*array += 1;
		_fill_array_from_bst((a_root) -> right, &(*array));
	}
}

BST create_bst(const int* array, int size) {
	BST bst = { .root = NULL, .size = size };
	for(int i = 0; i < size; i++) {
		_insert(array[i], &(bst).root);
	}
		
	return bst;
}

void tree_sort_array(int* array, size_t size) {
	BST bst = create_bst(array, size);
	_fill_array_from_bst(bst.root, &(array));
	empty_bst(&(bst));


	int temp;

	for(int i = 0; i < size; i++) {
		for(int j = i + 1; j < size; j++) {
			if(array[i] > array[j]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}

}

void _print_array(int* array, size_t size) {
	for(int k = 0; k < size; k++) {
		printf("%d ", array[k]);
	}
}

void empty_bst(BST* bst) {
	_destroy(&(bst) -> root);
}
*/

int _compare_for_qsort(const void* o1, const void* o2) {
	return ( *(int*)o1 - *(int*)o2 );
}

void quick_sort_array(int* array, size_t size) {
	qsort(array, size, sizeof(int), _compare_for_qsort);
}

void _print_array(int* array, size_t size) {
	for(int k = 0; k < size; k++) {
		printf("%d ", array[k]);
	}
}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
