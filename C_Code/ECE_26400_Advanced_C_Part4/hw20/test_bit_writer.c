#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "bit_writer.h"

//#define test(condition) assert(condition) 
#define test(condition) 

static void _test_simple() {
	printf("Starting test simple\n");
	BitWriter writer1 = open_bit_writer("xyz.bits");
	assert(writer1.file != NULL);
	assert(writer1.current_byte == 0);
	assert(writer1.num_bits_left == 8);
	write_bits(&writer1, 0xff, 4);
	assert(writer1.current_byte == 0xf0);
	assert(writer1.num_bits_left == 4);

	write_bits(&writer1, 0x0b, 4);
	assert(writer1.current_byte == 0x00);
	assert(writer1.num_bits_left == 8);
	close_bit_writer(&writer1);
	assert(writer1.current_byte == 0);
	assert(writer1.num_bits_left == 8);
	assert(writer1.file == NULL);
	printf("Simple passed!\n");

}
static void _test_overflow() {
	printf("Starting test over_flow\n");
	BitWriter writer1 = open_bit_writer("xyz.bits");
	assert(writer1.file != NULL);
	assert(writer1.current_byte == 0);
	assert(writer1.num_bits_left == 8);
	write_bits(&writer1, 0xff, 4);
	assert(writer1.current_byte == 0xf0);
	assert(writer1.num_bits_left == 4);

	write_bits(&writer1, 0x0b, 5);
	assert(writer1.current_byte == 0x80);
	assert(writer1.num_bits_left == 7);
	close_bit_writer(&writer1);
	assert(writer1.current_byte == 0);
	assert(writer1.num_bits_left == 8);
	assert(writer1.file == NULL);
	printf("Overflow passed!\n");
}

int main(int argc, char* argv[]) {
	/*BitWriter writer = open_bit_writer("file.bits");
	write_bits(&writer, 0xff, 8);
	close_bit_writer(&writer);
*/
	BitWriter writer = open_bit_writer("file.bits");
	write_bits(&writer, 0xff, 4);
	write_bits(&writer, 0x9f, 5);
	close_bit_writer(&writer);

	_test_simple();
	_test_overflow();

	test(false);

	return EXIT_SUCCESS;

}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
