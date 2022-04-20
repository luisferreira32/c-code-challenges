void printArray(int *Array, int size)
{
	for (int i = 0; i < size; ++i) printf("[DEBUG] %d\n", Array[i]);
}

void SWAP(int *params, int i, int j)
{
	int temp = params[i];
	params[i] = params[j];
	params[j] = temp;
}

