#include <stdio.h>
#include <string.h>
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

static unsigned char* _read_file(const char* filename) {
	FILE* fp = fopen(filename, "r");
	fseek(fp, 0, SEEK_END); // set file position to the last character in file
	int num_chars = ftell(fp);
	unsigned char* ch = malloc(sizeof(num_chars));
	fseek(fp, 0, SEEK_SET);
	fread(ch, num_chars, 1, fp);

	fclose(fp);
	return ch;
}

/*
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
*/

int main(int argc, char* argv[]) {

	const char* filename1 = _write_file("huffman fluffs many mums", "abc.txt"); 
	unsigned char* file_contents = _read_file(filename1);
	Frequencies freqs1 = { 0 };
	const char* error1 = NULL;
	calc_frequencies(freqs1, filename1, &error1);
	Node* head1 = make_huffman_pq(freqs1);
	TreeNode* tree1 = make_huffman_tree(head1);
	BitWriter writer1 = open_bit_writer(filename1);
	write_compressed(tree1, &writer1, file_contents);
	
	close_bit_writer(&writer1);
	free(file_contents);
	destroy_huffman_tree(&tree1);
	printf("\n");

	char const* filename2 = "xyz.txt";
	Frequencies freqs2 = { 0 };
	char const* error2 = NULL;
	calc_frequencies(freqs2, filename2, &error2);
	printf("\n");

	const char* filename3 = _write_file("huffman fluffs many mums", "abc.txt"); 
	Frequencies freqs3 = { 0 };
	const char* error3 = NULL;
	calc_frequencies(freqs3, filename3, &error3);
	Node* head3 = NULL;
	make_huffman_tree(head3);

	return EXIT_SUCCESS;
}
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
