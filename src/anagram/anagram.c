#include <stdio.h>

#include "quicksort.h"
#include "util.h"

int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61,
	67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157,
	163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257,
	263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367,
	373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 
	479, 487, 491, 499, 503, 509, 521, 523, 541};

const char portugues[] = "abcdefghijklmnopqrstuvwxyz";
const int PT = sizeof(portugues) / sizeof(portugues[0]);

int getHash(char *str, int SIZE)
{
	int hash = 1;
	for (int i = 0; i < SIZE; i++)
	{
		char c = tolower(str[i]);
		for (int j = 0; i < PT; j++)
		{
			if (c == portugues[j])
			{
				hash *= primes[j];
				break;
			}
		}
	}
	return hash;
}

/* anagram challenge runner */
void anagram_mock()
{
	char str_0[] = "anagram";
	char str_1[] = "aaagmnr";
	printf("%s = %d\n", str_0, getHash(str_0, 7));
	printf("%s = %d\n", str_1, getHash(str_1, 7));
    printf("[INFO] Anagram mock has ran!\n");
}


