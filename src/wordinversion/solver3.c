#include <stdio.h>
#include "solver3.h"
#include "util.h"
#include "quicksort.h"

char *wi_solver3(char *input, int input_size)
{
	int left_spc = -1, right_spc = input_size;
	for (int i = 0; i < input_size/2; i++)
	{
		char_SWAP(input, i, input_size-i-1);
		if (input[i] == ' ') {
			char_invertSubArray(input, left_spc+1, i-1);
			left_spc = i;
		}
		if (input[input_size-i-1] == ' ') {
			char_invertSubArray(input, input_size-i, right_spc-1);
			right_spc = input_size-i-1;
		}
	}
	int middle = input_size/2;
	if (input[middle] == ' ')
	{
		char_invertSubArray(input, ++left_spc, middle-1);
		char_invertSubArray(input, middle+1, --right_spc);
	} else {
		char_invertSubArray(input, ++left_spc, --right_spc);
	}
	return input;
}
