#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "print_integer.h"

void print_integer(int n, int radix, char* prefix) {
	int remainder; //remainder of number after divided by radix
	int index = 0; //iteration for how many times number needes to be divided
	int duplicate_n = n; //duplication of the number to make calculations easier
	bool x = false; //control variable on when to print remainder
	
	 if((n < radix) && (-n < radix)) {
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
