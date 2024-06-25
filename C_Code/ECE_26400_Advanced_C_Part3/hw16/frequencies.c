#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include "frequencies.h"

bool calc_frequencies(Frequencies freqs, const char* path, const char** a_error) {
	FILE* fp = fopen(path, "r");
	if(fp == NULL) {
		*a_error = strerror(errno);
		printf("Error: %s", *a_error);
		return false;
	}
	else {
		for(unsigned char ch = fgetc(fp); ! feof(fp); ch = fgetc(fp)) {
			freqs[ch]++;
		}
		return true;
	}

	fclose(fp);
}
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
