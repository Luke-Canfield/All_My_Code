#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "frequencies.h"
#include "clog.h"

char const* _write_file(char const* s, char const* filename) {
	FILE* fp = fopen(filename, "w");
	fputs(s, fp);
	fclose(fp);

	return filename;
}

void _print_freqs(Frequencies freqs) {
	for(int n = 0; n <= 255; n++) {
		if(freqs[n] != 0) {
			printf("%c=%ld ", n, freqs[n]);
		}
	}
	printf("\n");

}

int main(int argc, char* argv[]) {

	char const* filename1 = _write_file("ABC", "abc.txt"); 
	Frequencies freqs1 = { 0 }; 
	char const* error1 = NULL;
	bool did_succeed1 = calc_frequencies(freqs1, filename1, &error1);
	_print_freqs(freqs1);
	log_bool(did_succeed1);
	printf("\n");
	
	char const* filename2 = _write_file("ABCABCABC", "abc.txt"); 
	Frequencies freqs2 = { 0 }; 
	char const* error2 = NULL;
	bool did_succeed2 = calc_frequencies(freqs2, filename2, &error2);
	_print_freqs(freqs2);
	log_bool(did_succeed2);
	printf("\n");
	
	char const* filename3 = _write_file("aadjeiruvndjeifj", "abc.txt"); 
	Frequencies freqs3 = { 0 }; 
	char const* error3 = NULL;
	bool did_succeed3 = calc_frequencies(freqs3, filename3, &error3);
	_print_freqs(freqs3);
	log_bool(did_succeed3);
	printf("\n");
	
	char const* filename4 = _write_file("1243abc", "abc.txt"); 
	Frequencies freqs4 = { 0 }; 
	char const* error4 = NULL;
	bool did_succeed4 = calc_frequencies(freqs4, filename4, &error4);
	_print_freqs(freqs4);
	log_bool(did_succeed4);
	printf("\n");
	
	char const* filename5 = _write_file("!@#$%^&*(", "abc.txt"); 
	Frequencies freqs5 = { 0 }; 
	char const* error5 = NULL;
	bool did_succeed5 = calc_frequencies(freqs5, filename5, &error5);
	_print_freqs(freqs5);
	log_bool(did_succeed5);
	printf("\n");
	
	char const* filename6 = _write_file("/.,gjf", "abc.txt"); 
	Frequencies freqs6 = { 0 }; 
	char const* error6 = NULL;
	bool did_succeed6 = calc_frequencies(freqs6, filename6, &error6);
	_print_freqs(freqs6);
	log_bool(did_succeed6);
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
