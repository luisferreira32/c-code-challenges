#include <stdio.h>

void printArray(int *Array, int size)
{
	for (int i = 0; i < size; ++i) printf("[DEBUG] %d\n", Array[i]);
}

void int_SWAP(int *params, int i, int j)
{
	int temp = params[i];
	params[i] = params[j];
	params[j] = temp;
}

void char_SWAP(char *params, int i, int j)
{
	char temp = params[i];
	params[i] = params[j];
	params[j] = temp;
}

void char_invertSubArray(char *params, int from, int to)
{
	int middle = (1 + to - from) / 2;
	for (int i = 0; i < middle; i++) char_SWAP(params, from+i, to-i);
}
