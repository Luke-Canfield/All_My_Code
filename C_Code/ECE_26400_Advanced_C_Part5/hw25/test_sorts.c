#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "sorts.h"

int main(int argc, char* argv[]) {
	int array[] = {2, 1, 3, 4, 5, 6, 7};
	size_t size = sizeof(array) / sizeof(*array);
	//tree_sort_array(array, size);
    quick_sort_array(array, size);	
	_print_array(array, size);

	return EXIT_SUCCESS;
}
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
