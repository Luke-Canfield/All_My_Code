#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <assert.h>
#include "mintf.h"

void mintf(const char *format, ...) {
	va_list more_args;
	va_start(more_args, format);
	int i = 0;

	while(*format != '\0') {
		if((format[i] == '%') & (format[i + 1] == 'd')) {
			int next_num = va_arg(more_args, int);
			print_integer(next_num, 10, "");
			format++;
		}
		else if((format[i] == '%') & (format[i + 1] == 'x')) {
			int next_num = va_arg(more_args, int);
			print_integer(next_num, 16, "0x");
			format++;
		}
		else if((format[i] == '%') & (format[i + 1] == 'o')) {
			int next_num = va_arg(more_args, int);
			print_integer(next_num, 8, "");
			format++;
		}
		else if((format[i] == '%') & (format[i + 1] == 'b')) {
			int next_num = va_arg(more_args, int);
			print_integer(next_num, 2, "0b");
			format++;
		}
		else if((format[i] == '%') & (format[i + 1] == 's')) {
			char* next_num = va_arg(more_args, char*);
			fputc(*next_num, stdout);
			format++;
		}
		else if((format[i] == '%') & (format[i + 1] == '%')) {
			fputc('%', stdout);
			format++;
		}
		else if((format[i] == '%') & (format[i + 1] == '$')) {
			int next_num = va_arg(more_args, int);
			print_integer(next_num, 10, "$");
			format++;
		}
		else {
			fputc(*format, stdout);
		}
		format++;
	}

	va_end(more_args);

	return;
}

void print_integer(int n, int radix, char* prefix) {
	int remainder; //remainder of number after divided by radix
	int index = 0; //iteration for how many times number needes to be divided
	int duplicate_n = n; //duplication of the number to make calculations easier
	bool x = false; //control variable on when to print remainder

	 if(*prefix == '$') { 
		int cents = n % 100;
		n = n / 100;
        if(abs(n) < 10) {
			if(cents <= 0) {
				fputc('-', stdout);
				cents = cents * -1;
				n = n * -1;
				for(int idx_prefix = 0; prefix[idx_prefix] != '\0'; idx_prefix++) {
			 		fputc(prefix[idx_prefix], stdout);
				}
		    	fputc('0' + n, stdout);	
				}
			else {
				for(int idx_prefix = 0; prefix[idx_prefix] != '\0'; idx_prefix++) {
			 		fputc(prefix[idx_prefix], stdout);
				}
				fputc('0' + n, stdout);
			}
			fputc('.', stdout);
			if (cents < 10) {
				fputc('0', stdout);
			}
			print_integer(cents, 10, "");
	 	}
		else {
			if(duplicate_n < 0) {
				duplicate_n = duplicate_n * -1;
				n = n * -1;
				fputc('-', stdout);
			}
			for(int idx_prefix = 0; prefix[idx_prefix] != '\0'; idx_prefix++) {
				 fputc(prefix[idx_prefix], stdout); 
			}
			while(duplicate_n != 0) {
				duplicate_n = duplicate_n / radix;
				index++;
			}
			for(int k = index - 1; k > -1; k--) {
				duplicate_n = n;
				for(int j = k; j > 0; j--) {
					duplicate_n = duplicate_n / radix;
				}
				remainder = duplicate_n % radix;
				if(remainder > 0) {
					x = true;
				}
				if(x) {
					if(remainder > 9) {
						remainder = remainder + 39;
						fputc('0' + remainder, stdout);
					}
					else {
						fputc('0' + remainder, stdout);
					}
				}
			}
			fputc('.', stdout);
				if(cents < 10) {
				fputc('0', stdout);
			}
			print_integer(cents, 10, "");
		}
	}
	else if((n < radix) && (-n < radix)) {
		 if(n < 0) {
			 n = n * -1;
			 fputc('-', stdout);
			 for(int idx_prefix = 0; prefix[idx_prefix] != '\0'; idx_prefix++) {
			 	fputc(prefix[idx_prefix], stdout); 
			 }
		 }
			 if(n > 9) {
				n = n + 39;
			 	fputc('0' + n, stdout);
		 	 }
		 else {
			 if(n > 9) {
				n = n + 39;
			 }
		 	fputc('0' + n, stdout);	
			 
		 }
	 }
	 else {
		 if(duplicate_n < 0) {
			duplicate_n = duplicate_n * -1;
			n = n * -1;
			fputc('-', stdout);
		}
		for(int idx_prefix = 0; prefix[idx_prefix] != '\0'; idx_prefix++) {
			 fputc(prefix[idx_prefix], stdout); 
		}
		while(duplicate_n != 0) {
			duplicate_n = duplicate_n / radix;
			index++;
		}
		for(int k = index - 1; k > -1; k--) {
			duplicate_n = n;
			for(int j = k; j > 0; j--) {
				duplicate_n = duplicate_n / radix;
			}
			remainder = duplicate_n % radix;
			if(remainder > 0) {
				x = true;
			}
			if(x) {
				if(remainder > 9) {
					remainder = remainder + 39;
					fputc('0' + remainder, stdout);
				}
				else {
					fputc('0' + remainder, stdout);
				}
			}
		}
	}

	return;
}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
