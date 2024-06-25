// ***
// *** You must modify this file
// ***

#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// do not modify this function
static void printDeck(CardDeck deck)
{
  int ind;
  for (ind = 0; ind < deck.size; ind ++)
    {
      printf("%c ", deck.cards[ind]);
    }
  printf("\n");
}

#ifdef TEST_DIVIDE
// leftDeck and rightDeck are arrays of CardDeck
// This function creates pairs of left and right decks
// Each pair divides the original deck into two non-overlapping decks and
// together they form the original deck.
//
// You can think of the left deck held by the left hand taking some
// cards (at least one) from the top of the original deck.
//
// The right deck is held by the right hand taking some (at least one)
// cards from the bottom of the original deck.
void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck) {
	int num_pairs = origDeck.size - 1;

	for(int i = 0; i < num_pairs; i++) {
		// create leftDeck
		leftDeck[i].size = i + 1;
		memcpy(leftDeck[i].cards, origDeck.cards, leftDeck[i].size * sizeof(CardDeck));
		// create rightDeck
		rightDeck[i].size = origDeck.size - leftDeck[i].size;
		memcpy(rightDeck[i].cards, &origDeck.cards[i+1], rightDeck[i].size * sizeof(CardDeck));
	}
}
#endif

#ifdef TEST_INTERLEAVE

// Interleave two decks to generate all possible results.
//
// If the leftDeck is {'A'} and the right deck is {'2', '3'}, this
// function prints
// A 2 3
// 2 A 3
// 2 3 A
//
// If the leftDeck is {'A', '2'} and the right deck is {'3', '4'}, this
// function prints 
// 3 4 A 2
// 3 A 4 2
// A 3 4 2 
// 3 A 2 4 
// A 3 2 4 
// A 2 3 4 
//
// Please notice the space does not matter because grading will use
// diff -w
//
// How to generate all possible interleaves?

// Understand that a card at a particular position can come from
// either left or right (two options). The following uses left for
// explanation but it is equally applicable to the right.
//
// After taking one card from the left deck, the left deck has one
// fewer card. Now, the problem is the same as the earlier problem
// (thus, this problem can be solved by using recursion), excecpt one
// left card has been taken. Again, the next card can come from left
// or right.
//
// This process continues until either the left deck or the right deck
// runs out of cards. The remaining cards are added to the result.
// 
// It is very likely that you want to create a "helper" function that
// can keep track of some more arguments.  If you create a helper
// function, please keep it inside #ifdef TEST_INTERLEAVE and #endif
// so that the function can be removed for grading other parts of the
// program.

void helper_func(CardDeck left, CardDeck right, CardDeck result, int l_index, int ri_index, int re_index) {
		if(l_index > left.size) {
			for(int i = 0; i < right.size; i++) {
				result.cards[re_index] = right.cards[ri_index];
				re_index++;
				ri_index++;
			}
			printDeck(result);
			return;
		}
		if(ri_index > right.size) {
			for(int j = 0; j < left.size; j++) {
				result.cards[re_index] = right.cards[ri_index];
				re_index++;
				ri_index++;
			}
			printDeck(result);
			return;
		}
		result.cards[re_index] = left.cards[l_index];
		helper_func(left, right, result, l_index + 1, ri_index, re_index + 1);

		result.cards[re_index] = right.cards[ri_index];
		helper_func(left, right, result, l_index, ri_index + 1, re_index + 1);
	}

void interleave(CardDeck leftDeck, CardDeck rightDeck) {
	int num_cards = leftDeck.size + rightDeck.size;

	CardDeck resultDeck;
	resultDeck.size = num_cards;

	int left_index = 0;
	int right_index = 0;
	int result_index = 0;

	helper_func(leftDeck, rightDeck, resultDeck, left_index, right_index, result_index);
}

#endif

#ifdef TEST_SHUFFLE
// The shuffle function has the following steps:

// 1. calculate the number of possible left and right decks. It is
// the number of cards - 1 because the left deck may have 1, 2,...,
// #cards - 1 cards.
//
// 2. allocate memory to store these possible pairs of left and right
// decks.
//
// 3. send each pair to the interleave function
//
// 4. release allocated memory
//
void shuffle(CardDeck origDeck) {
	int num_pairs = origDeck.size - 1; // 1.

	CardDeck *left = malloc(num_pairs * sizeof(CardDeck)); // 2.
	CardDeck *right = malloc(num_pairs * sizeof(CardDeck)); // 2.

	divide(origDeck, left, right);
	
	for(int i = 0; i < num_pairs; i++) {
		interleave(left[i], right[i]);     // 3.
	}

	for(int j = 0; j < num_pairs; j++) {
		free(left[j].cards);                           // 4.
		free(right[j].cards);
	}

	free(left);
	free(right);

}
#endif
