#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "btree.h"

// Instructor solution add/removes about 25 lines in this file.

int query_min(BTreeNode* root) {
	while(get_subtree(root, 0) != NULL) {
		root = get_subtree(root, 0);
	}

	return root->keys[0];
}

int query_max(BTreeNode* root) {
	while(get_subtree(root, root -> num_keys) != NULL) {
		root = get_subtree(root, root -> num_keys);
	}
	
	return root -> keys[(root -> num_keys) - 1];
}

void large_traversal(BTreeNode* root, int* largest_keys, int* keys_found, int k) {
	if(root == NULL || *keys_found >= k) {
		return;
	}

	large_traversal(get_subtree(root, root -> num_keys), largest_keys, keys_found, k);

	for(int i = root -> num_keys - 1; i >= 0 && *keys_found < k; i--) {
		largest_keys[*keys_found] = root -> keys[i];
		(*keys_found)++;
		large_traversal(get_subtree(root, i), largest_keys, keys_found, k);
	}
}

KeyQueryResult query_k_largest(BTreeNode* root, size_t k) {

	int* k_largest_keys = malloc(k * sizeof *k_largest_keys);
	int num_keys_found = 0;

	large_traversal(root, k_largest_keys, &num_keys_found, k);

	return (KeyQueryResult) { .keys = k_largest_keys, .num_keys = num_keys_found };
}

void small_traversal(BTreeNode* root, int* smallest_keys, int* keys_found, int k) {
	if(root == NULL || *keys_found >= k) {
		return;
	}

	small_traversal(get_subtree(root, 0), smallest_keys, keys_found, k);

	for(int i = 0; i < root -> num_keys && *keys_found < k; i++) {
		smallest_keys[*keys_found] = root -> keys[i];
		(*keys_found)++;
		small_traversal(get_subtree(root, i + 1), smallest_keys, keys_found, k);
	}
}

KeyQueryResult query_k_smallest(BTreeNode* root, size_t k) {
	int* k_smallest_keys = malloc(k * sizeof *k_smallest_keys);
	int num_keys_found = 0;

	small_traversal(root, k_smallest_keys, &num_keys_found, k);
	
	return (KeyQueryResult) { .keys = k_smallest_keys, .num_keys = num_keys_found };
}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
