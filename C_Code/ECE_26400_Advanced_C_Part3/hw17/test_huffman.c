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

static void _print_freqs(Frequencies freqs) {
	for(int n = 0; n <= 255; n++) {
		if(freqs[n] != 0) {
			printf("%c=%ld ", n, freqs[n]);
		}
	}
	printf("\n");
}

//static void _print_ints(Node* head) {
//	for(Node* curr = head; curr != NULL; curr = curr -> next) {
//		printf("%d ", *(int*)curr -> a_value);
//	}
//	printf("\n");
//}

static void _print_strings(Node* head) {
	for(Node* curr = head; curr != NULL; curr = curr -> next) {
		printf("%s ", (char*)(curr -> a_value));
	}
	printf("\n");
}

static void _free_avalue(void* value) {
	//free(value);
}

int main(int argc, char* argv[]) {
	Node* head1 = NULL;
	char const* filename1 = _write_file("zzbbox?", "abc.txt");
	Frequencies freqs1 = { 0 };
	char const* error1 = NULL;
	calc_frequencies(freqs1, filename1, &error1);
	head1 = make_huffman_pq(freqs1);
	_print_strings(head1);
	//_print_ints(head);
	destroy_list(&head1, _free_avalue);
	printf("\n");

	Node* head = NULL;
	char const* filename = _write_file("BBAAAEEEEC", "abc.txt");
	Frequencies freqs = { 0 };
	char const* error = NULL;
	calc_frequencies(freqs, filename, &error);
	head = make_huffman_pq(freqs);
	_print_strings(head);
	//_print_ints(head);
	destroy_list(&head, _free_avalue);
	printf("\n");
	
	char const* filename7 = "ab.txt"; 
	Frequencies freqs7 = { 0 }; 
	char const* error7 = NULL;
	bool did_succeed7 = calc_frequencies(freqs7, filename7, &error7);
	_print_freqs(freqs7);
	log_bool(did_succeed7);

	return EXIT_SUCCESS;
}
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
