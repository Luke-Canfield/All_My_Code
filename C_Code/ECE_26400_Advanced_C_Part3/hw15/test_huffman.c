#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "huffman.h"

static int _compare_for_strings(const void* o1, const void* o2) {
	size_t len_1 = strlen(o1);
	size_t len_2 = strlen(o2);
	return len_1 - len_2;
}

static int _compare_for_ints(const void* o1, const void* o2) {
	return (*(const int *)o1 - *(const int*)o2 );
}

static void _print_ints(Node* head) {
	for(Node* curr = head; curr != NULL; curr = curr -> next) {
		printf("%d ", *(int*)curr -> a_value);
	}
	printf("\n");
}

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
	Node* head = NULL;
	int n1[] = {10, 14};
	pq_enqueue(&head, &n1[0], _compare_for_ints); 
	pq_enqueue(&head, &n1[1], _compare_for_ints);
	_print_ints(head);
	destroy_list(&head, _free_avalue);

	Node* head1 = NULL;
	int n2[] = {100, 99, 88, 77, 104, 65};
	pq_enqueue(&head1, &n2[0], _compare_for_ints); 
	pq_enqueue(&head1, &n2[1], _compare_for_ints);
	pq_enqueue(&head1, &n2[2], _compare_for_ints); 
	pq_enqueue(&head1, &n2[3], _compare_for_ints);
	pq_enqueue(&head1, &n2[4], _compare_for_ints); 
	pq_enqueue(&head1, &n2[5], _compare_for_ints);
	_print_ints(head1);
	destroy_list(&head1, _free_avalue);
	
	Node* head2 = NULL;
	char* s = "hello";
	char* s1 = "I";
	char* s2 = "excited";
	pq_enqueue(&head2, s, _compare_for_strings); 
	pq_enqueue(&head2, s1, _compare_for_strings);
	pq_enqueue(&head2, s2, _compare_for_strings);
	_print_strings(head2);
	destroy_list(&head2, _free_avalue);

	Node* head3 = NULL;
	char* ch1 = "monday";
	char* ch2 = "cat";
	char* ch3 = "yellow";
	char* ch4 = "four";
	char* ch5 = "hi";
	pq_enqueue(&head3, ch1, _compare_for_strings); 
	pq_enqueue(&head3, ch2, _compare_for_strings);
	pq_enqueue(&head3, ch3, _compare_for_strings);
	pq_enqueue(&head3, ch4, _compare_for_strings);
	pq_enqueue(&head3, ch5, _compare_for_strings);
	_print_strings(head3);
	destroy_list(&head3, _free_avalue);

	return EXIT_SUCCESS;
}
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */

