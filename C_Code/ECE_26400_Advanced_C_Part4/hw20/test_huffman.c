#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "huffman.h"
#include "clog.h"

static char const* _write_file(char const* s, char const* filename) {
	FILE* fp = fopen(filename, "w");
	fputs(s, fp);
	fclose(fp);

	return filename;
}

static void _print_tree(TreeNode* tree) {
	if(tree != NULL) {
		printf("[%c]=[%ld]  ",(tree -> character), tree -> frequency);
		if(tree -> left != NULL) {
			_print_tree(tree -> left);
		}
		if(tree -> right != NULL) {
			_print_tree(tree -> right);
		}
	}
}

int main(int argc, char* argv[]) {

	Node* head1 = NULL;
	TreeNode* tree1 = NULL;
	BitWriter writer1 = open_bit_writer("code.bits");
	char const* filename1 = _write_file("huffman fluffs many mums", "abc.txt");
	Frequencies freqs1 = { 0 };
	char const* error1 = NULL;
	calc_frequencies(freqs1, filename1, &error1);
	head1 = make_huffman_pq(freqs1);
	tree1 = make_huffman_tree(head1);
	write_coding_table(tree1, &writer1);
	close_bit_writer(&writer1);
	_print_tree(tree1);
	destroy_huffman_tree(&tree1);
	printf("\n");

	Node* head2 = NULL;
	TreeNode* tree2 = NULL;
	char const* filename2 = "xyz.txt";
	Frequencies freqs2 = { 0 };
	char const* error2 = NULL;
	calc_frequencies(freqs2, filename2, &error2);
	head2 = make_huffman_pq(freqs2);
	tree2 = make_huffman_tree(head2);
	_print_tree(tree2);
	destroy_huffman_tree(&tree2);
	printf("\n");

	return EXIT_SUCCESS;
}
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
