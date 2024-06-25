#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "huffman.h"

static int _compare_for_freqs(const void* o1, const void* o2) {
	TreeNode* tree1 = (TreeNode *)o1;
	TreeNode* tree2 = (TreeNode *)o2;
	if((tree1 -> frequency) - (tree2 -> frequency) != 0) {
		return ((tree1 -> frequency) - (tree2 -> frequency));
	}
	else {
		return ((tree1 -> character) - (tree2 -> character));
	}
}

Node* make_huffman_pq(Frequencies freqs) {
	Node* head = NULL;
	for(int n = 0; n<= 255; n++) {
		if(freqs[n] != 0) {
			TreeNode* tree = malloc(sizeof(*tree));
			*tree = (TreeNode) { .frequency = freqs[n], .character = n };
			pq_enqueue(&head, tree, _compare_for_freqs);
		}
	}
	return head;
}

TreeNode* make_huffman_tree(Node* head) {
	if(head == NULL) {
		return NULL;
	}
	while(head -> next != NULL) {
		TreeNode* tree_head = malloc(sizeof(*tree_head));
		*tree_head = (TreeNode) { .left = head -> a_value, .right = head -> next -> a_value, .character = '\0' };
		tree_head -> frequency = (tree_head -> left -> frequency) + (tree_head -> right -> frequency); 
		Node* old_head = pq_dequeue(&head);
		free(old_head);
		old_head = pq_dequeue(&head);
		free(old_head);
		pq_enqueue(&head, tree_head, _compare_for_freqs);
	}
	TreeNode* root = head -> a_value;
	free(head);
	return root;
}

void destroy_huffman_tree(TreeNode** a_root) {
	if(*a_root != NULL) {
		destroy_huffman_tree(&((*a_root) -> left));
		destroy_huffman_tree(&((*a_root) -> right));
		free(*a_root);
		//*a_root = NULL;
	}
}


/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
