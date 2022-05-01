#include <stdio.h>
#include "solver3.h"
#include "util.h"
#include "quicksort.h"

char *wi_solver3(char *input, int input_size)
{
	// Track the last 2 spaces found within the string.
	int left_spc = -1, right_spc = input_size;
	for (int i = 0; i < input_size/2; i++)
	{
		// invert the string in place
		char_SWAP(input, i, input_size-i-1);
		/* if we find a space, re-invert the word it encompasses
		 * this is always done after inverting the word, such that
		 * the final word is correctly spelled */
		if (input[i] == ' ') {
			char_invertSubArray(input, left_spc+1, i-1);
			left_spc = i;
		}
		if (input[input_size-i-1] == ' ') {
			char_invertSubArray(input, input_size-i, right_spc-1);
			right_spc = input_size-i-1;
		}
	}
	/* 2 possible edge cases:
	 * 1- the middle of the string is a space
	 * 2- the middle of the string is within a word */
	int middle = input_size/2;
	if (input[middle] == ' ')
	{
		// If the middle is a space, invert the words to the left and right
		char_invertSubArray(input, ++left_spc, middle-1);
		char_invertSubArray(input, middle+1, --right_spc);
	} else {
		// If we are within a word, invert this as it is the last word
		char_invertSubArray(input, ++left_spc, --right_spc);
	}

	return input;
}
