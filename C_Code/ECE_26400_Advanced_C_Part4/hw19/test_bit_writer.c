#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "bit_writer.h"

int main(int argc, char* argv[]) {
	BitWriter writer = open_bit_writer("file.bits");
	write_bits(&writer, 0xff, 8);
	close_bit_writer(&writer);
	
	BitWriter writer1 = open_bit_writer("xyz.bits");
	write_bits(&writer1, 0xff, 4);
	write_bits(&writer1, 0x0b, 5);
	close_bit_writer(&writer1);

	return EXIT_SUCCESS;

}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
