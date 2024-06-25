#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "btree.h"

int main(int argc, char* argv[]) {
//	srand(1);
	BTreeNode* root = NULL;
/*	insert(&root, 6);
	print_btree(root);
	insert(&root, 8);
	print_btree(root);
	insert(&root, 9);
	print_btree(root);
	insert(&root, 7);
	print_btree(root);
	insert(&root, 5);
	print_btree(root);
	insert(&root, 1);
	print_btree(root);
	insert(&root, 2);
	print_btree(root);
*/

	// Uncomment if you want to see this on a large btree.
	//
	// Make the b-tree huge (>400 keys)
	for(int i = 0; i < 40; i++) {
		int random_num = rand() % 100;
		bool did_insert = insert(&root, random_num);
		if(!did_insert) {
			printf("Did not insert %d because it is already in the btree.\n", random_num);
		}
	}
	//print_keys(root, "Root: ", ", ", "\n");
	print_btree(root);

	print_keys(root, "Keys: [", " → ", "]\n");

	//Test for query_min
	int min_key = query_min(root);
	printf("The min_key in the B-Tree is: %d\n", min_key);

	//Test for query_max
	int max_key = query_max(root);
	printf("The max_key in the B-Tree is: %d\n", max_key);

	//Test for query_k_largest
	KeyQueryResult largest_5 = query_k_largest(root, 5);
	for(int i = 0; i < largest_5.num_keys; i++) {
		printf("largest_5.keys[%d] == %d\n", i, largest_5.keys[i]);
	}

	//Test for query_k_smallest
	KeyQueryResult smallest_4 = query_k_smallest(root, 4);
	for(int i = 0; i < smallest_4.num_keys; i++) {
		printf("smallest_4.keys[%d] == %d\n", i, smallest_4.keys[i]);
	}

	//Test 1 for get_in_order_successor & get_in_order_predecessor 
	KeyLocation key_location;
	key_location.node = root;
	key_location.key_idx = 0;
	key_location.key = root -> keys[key_location.key_idx];
	KeyLocation successor = get_in_order_successor(key_location);
	KeyLocation predecessor = get_in_order_predecessor(key_location);
	printf("Key: %d\n", key_location.key);
	printf("Successor Key: %d\n", successor.key);
	printf("Predecessor Key: %d\n", predecessor.key);

	//Test for shift_key_forward
	//printf("Test for shift_key_forward(root, 0)\n");
	//shift_key_forward(root, 0);
	//print_btree(root);

	//Test for shift_key_backward
	//printf("Test for shift_key_backward(root, 1)\n");
	//shift_key_backward(root, 1);
	//print_btree(root);
	
/*	//Test 1 for delete_key
    printf("Test for deleting leaf node: delete_key(&root, 6)\n");
	bool success = delete_key(&root, 6);
	printf(success ? "Successful Deletion\n" : "Key didn't exist\n");
	print_btree(root);
	assert_node_correct(root);

	//Test 2 for delete_key
    printf("Test for deleting internal node: delete_key(&root, 7)\n");
	bool success_1 = delete_key(&root, 7);
	printf(success_1 ? "Successful Deletion\n" : "Key didn't exist\n");
	print_btree(root);
	assert_node_correct(root);
	
	//Test 3 for delete_key 
    printf("Test for deleting internal node which requires merging: delete_key(&root, 8)\n");
	bool success_2 = delete_key(&root, 8);
	printf(success_2 ? "Successful Deletion\n" : "Key didn't exist\n");
	print_btree(root);
	assert_node_correct(root);
	
	//Test 4 for delete_key
    printf("Test for delete_key(&root, 3)\n");
	bool success_3 = delete_key(&root, 3);
	printf(success_3 ? "Successful Deletion\n" : "Key didn't exist\n");
	print_btree(root);
	assert_node_correct(root);
*/
	//Test 1 for delete_key 
    printf("Test for deleting 9 unique nodes\n");
	bool success = delete_key(&root, 11);
	bool success_1 = delete_key(&root, 21);
	bool success_2 = delete_key(&root, 15);
	bool success_3 = delete_key(&root, 42);
	bool success_4 = delete_key(&root, 82); 
	bool success_5 = delete_key(&root, 83); 
	bool success_6 = delete_key(&root, 25); 
	bool success_7 = delete_key(&root, 72); 
	bool success_8 = delete_key(&root, 67);
	printf(success ? "Successful Deletion\n" : "Key didn't exist\n");
	assert_node_correct(root);
	printf(success_1 ? "Successful Deletion\n" : "Key didn't exist\n");
	assert_node_correct(root);
	printf(success_2 ? "Successful Deletion\n" : "Key didn't exist\n");
	assert_node_correct(root);
	printf(success_3 ? "Successful Deletion\n" : "Key didn't exist\n");
	assert_node_correct(root);
	printf(success_4 ? "Successful Deletion\n" : "Key didn't exist\n");
	assert_node_correct(root);
	printf(success_5 ? "Successful Deletion\n" : "Key didn't exist\n");
	assert_node_correct(root);
	printf(success_6 ? "Successful Deletion\n" : "Key didn't exist\n");
	assert_node_correct(root);
	printf(success_7 ? "Successful Deletion\n" : "Key didn't exist\n");
	assert_node_correct(root);
	printf(success_8 ? "Successful Deletion\n" : "Key didn't exist\n");
	assert_node_correct(root);

	print_btree(root);

	free(largest_5.keys);
	free(smallest_4.keys);
	free_btree(&root);

	return EXIT_SUCCESS;
}
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
