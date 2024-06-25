#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "huffman.h"

typedef struct _BitCode {
	uint8_t bits; 
	int num_bits;
} BitCode;

static int _compare_for_freqs(const void* o1, const void* o2) {
	TreeNode* tree1 = (TreeNode *)o1;
	TreeNode* tree2 = (TreeNode *)o2;

	if((tree1 -> frequency) - (tree2 -> frequency) != 0) {
		return ((tree1 -> frequency) - (tree2 -> frequency));
	}
	else if(tree1 -> left != NULL && tree2 -> left == NULL) {
		return 1;
	}
	else {
		return (tree1 -> character) - (tree2 -> character);
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
	}
}
/*
void write_coding_table(TreeNode* root, BitWriter* a_writer) {
	if(root != NULL) {
		if(root -> left != NULL) {
			write_coding_table(root -> left, a_writer);
		}
		if(root -> right != NULL) {
			write_coding_table(root -> right, a_writer);
		}
		if(root -> character != 0) {
		    write_bits(a_writer, 0x01, 1);
		    write_bits(a_writer, (root -> character), 8);
		}
		else {
			write_bits(a_writer, 0x00, 1);
		}
	}
}
*/

void static _table_from_tree(TreeNode* root, BitCode* character_to_code, uint8_t _bits, int _num_bits) {
	if(root != NULL) {
		_table_from_tree(root -> left, character_to_code, _bits << 1, _num_bits + 1);
		_table_from_tree(root -> right, character_to_code, (_bits << 1) | 0x01, _num_bits + 1);
		if(root -> character != '\0') {
			character_to_code[root -> character] = (BitCode) { .bits = _bits, .num_bits = _num_bits };
		}
	}
}

void write_compressed(TreeNode* root, BitWriter* a_writer, uint8_t* uncompressed_bytes) {
	BitCode character_to_code[256] = { (BitCode) { .bits = 0x00, .num_bits = 0 } };
	_table_from_tree(root, character_to_code, 0x00, 0);
	
	for(int i = 0; uncompressed_bytes[i] != '\0'; i++) {
		write_bits(a_writer, character_to_code[uncompressed_bytes[i]].bits, character_to_code[uncompressed_bytes[i]].num_bits);
	}	
}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
