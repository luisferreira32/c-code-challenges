#include <stdio.h>
#include "solver3.h"
#include "util.h"

char *wi_solver3(char *input, int input_size)
{
	int L = 1 + (input_size / 2);
	int spaces[L];
	for (int i = 0; i < L; ++i) spaces[i] = 0;
	for (int i = 0; i < input_size; ++i) printf("%c", input[i]);
	printf("\n");
	int j = 0;
	for (int i = 0; i < input_size/2; i++)
	{
		char_SWAP(input, i, input_size-i-1);

		if (input[i] == ' ') 
		{
			/* printf("-%d", i); */
			spaces[j] = i;
			j++;
			input[i] = '_';
		}
		if (input[input_size-i-1] == ' ')
		{
			//printf("-%d", input_size-i-1);
			input[input_size-i-1] = '_';
			spaces[j] = input_size-i-1;
			j++;
		}
		printf("%d\n", j);

		//printf("%c ", input[i]);
		//printf("%c ", input[input_size-i-1]);
	}
	for (int i = 0; i < input_size; ++i) printf("%c", input[i]);
	printf("\n");
	for (int i = 0; i < L; ++i) printf("%d ", spaces[i++]);
	return input;
}
