#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "mintf.h"

int main(int argc, char* argv[]) {
	mintf("a");
	fputc('\n', stdout);

	mintf("Hello my name is Luke.");
	fputc('\n',stdout);
    
	mintf("1 + 2 = %d", 3);
	fputc('\n', stdout);

	mintf("We like percentages %%");
	fputc('\n', stdout);
	
	mintf("I have a 70% chance of getting a 90% on my exam.");
	fputc('\n', stdout);

	mintf("In hex I have %x crypto coins...", 455);
	fputc('\n', stdout);
	
	mintf("%d in binary is %b and in octal is %o", -7890, -7890, -7890);
	fputc('\n', stdout);

	mintf("The dog's name is %slifford Jr.", "C");
	fputc('\n', stdout);

	mintf("Bob's comb costed him %$!", 2);
	fputc('\n', stdout);

	mintf("Her socks were on sale for %$.", 46);
	fputc('\n', stdout);

	mintf("The discount was %$.", -5);
	fputc('\n', stdout);
	
	mintf("The difference was %$.", -34);
	fputc('\n', stdout);

	mintf("His credit card statement reads %$!!", -783);
	fputc('\n', stdout);

	mintf("She made %$ in %d!", 7500000, 2020);
	fputc('\n', stdout);

	mintf("There was %$ found in the ocean.", INT_MAX);
	fputc('\n', stdout);

	mintf("Excess parameter verification %d", 123, 234, 456);
	fputc('\n', stdout);

	return EXIT_SUCCESS;
}
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
