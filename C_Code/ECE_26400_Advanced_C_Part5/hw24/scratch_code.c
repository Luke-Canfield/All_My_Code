#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdarg.h>

// void print_nums(int nums, ...) {
	
//	va_list more_args;
//	va_start(more_args, nums);

//	for(int i = 0; i < nums; i++) {
//		int next_num = va_arg(more_args, int);
//		printf("%d\n", next_num);
//	}

//	va_end(more_args);

// }

//  void print_chars(int strings, ...) {
//	va_list more_args;
//	va_start(more_args, strings);

//	for(int j = 0; j < strings; j++) {
//		char* next_string = va_arg(more_args, char*);
//		printf("%s\n", next_string);
//	}

//	va_end(more_args);
// }

void mint(const char *format, ...) { 
	va_list more_args;
	va_start(more_args, format);
	int iterations = 0;
	int i = 0;

	while(*format != '\0') {
		if((format[i] == '%') & (format[i + 1] == 'd')) {
			int next_num = va_arg(more_args, int);
			printf("%d", next_num);
			//fputc(next_num, stdout);
			format++;
		}
		
		else {
			fputc(*format, stdout);
		}
		format++;
		iterations++;
	}

	va_end(more_args);
	fputc('\n', stdout);
	printf("%d",iterations);
}

int main(int argc, char* argv[]) {
 	
//	print_nums(4, 245, 5748, 504984, 78888);
//	print_chars(3, "Oh my goodness", "They're right there", "the game is almost over!");
    
	mint("478");
	fputc('\n', stdout);
	mint("I am going to be there in %d hours and %d minutes!", -10, 345);
	
	return EXIT_SUCCESS;
}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
