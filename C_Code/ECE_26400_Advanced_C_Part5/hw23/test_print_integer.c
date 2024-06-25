#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "print_integer.h"

int main(int argc, char* argv[]) {
	print_integer(4, 10, "");
	fputc('\n', stdout);

	print_integer(9, 2, "");
	fputc('\n', stdout);

    print_integer(8, 16, "");	
	fputc('\n', stdout);

	print_integer(12, 18, "");	
	fputc('\n', stdout);

	print_integer(25, 5, ""); print_integer(-234, 8, ""); print_integer(24, 3, "");	
	fputc('\n', stdout);

	print_integer(58, 8, "");	
	fputc('\n', stdout);

	print_integer(134, 10, "");
	fputc('\n', stdout);

	print_integer(678, 17, "");	
	fputc('\n', stdout);

	print_integer(-12, 23, "");
	fputc('\n', stdout);

	print_integer(4567, 36, "");
	fputc('\n', stdout);

	print_integer(-345, 17, "");	
	fputc('\n', stdout);

	print_integer(-1286, 20, "");
	fputc('\n', stdout);

	print_integer(4578910, 29, "");	
	fputc('\n', stdout);

    print_integer(1255387685, 15, "");	
	fputc('\n', stdout);

 	print_integer(-1259873463, 24, "");	
	fputc('\n', stdout);

 	print_integer(INT_MAX, 3, "");	
	fputc('\n', stdout);

 	print_integer(786, 15, "$");	
	fputc('\n', stdout);

 	print_integer(-435, 32, "#");	
	fputc('\n', stdout);
	
 	print_integer(900, 10, "$"); print_integer(-800, 10, "$");	
	fputc('\n', stdout);

	return EXIT_SUCCESS;
}
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
