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
	//return (*(const int *)o1 - *(const int*)o2 );
}

Node* make_huffman_pq(Frequencies freqs) {
	Node* head = NULL;
	for(int n = 0; n<= 255; n++) {
		if(freqs[n] != 0) {
			TreeNode* tree = malloc(sizeof(*tree));
			*tree = (TreeNode) { .frequency = freqs[n], .character = n };
			//printf("freq = %ld  ", tree -> frequency);
			//printf("character = %c\n", tree -> character);
			pq_enqueue(&head, tree, _compare_for_freqs);
		}
	}
			
	return head;
}
	
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
