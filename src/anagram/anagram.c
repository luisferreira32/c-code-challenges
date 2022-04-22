// std lib imports - the only ones allowed!
#include <stdio.h>
#include <stdlib.h>

// import your own headers
#include "anagram.h"

// and your own functions
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

#include "iohelper.h"

/* anagram challenge runner mock */
void anagram_mock()
{
	char str_0[] = "anagram";
	char str_1[] = "aaagmnr";
	printf("%s = %d\n", str_0, getHash(str_0, 7));
	printf("%s = %d\n", str_1, getHash(str_1, 7));
  printf("[INFO] Anagram mock has ran!\n");
}

/**
 * ================== HELPER FUNCTIONS ==================
 * These are helper functions for the anagram challenge
 */

/* anagram_dict_loader util function for anagram challenge */
char **anagram_dict_loader(const char *dict_path, int dict_word_n)
{
    char **dict = NULL;

    dict = (char **)malloc(sizeof(char *) * dict_word_n);
    if (dict == NULL)
    {
        printf("[ERROR] There was an error allocating memory for the dict\n");
        return NULL;
    }

    if (dict_reader(dict, dict_path, dict_word_n) == NULL)
    {
        return NULL;
    }

    // and now sort a bit!

    return dict;
}

/* anagram_dict_disposer util function for anagram challenge */
void anagram_dict_disposer(char **dict, int dict_word_n)
{
    if (dict != NULL)
    {
        dict_disposer(dict, dict_word_n);
    }
}

/**
 * ================ ANAGRAM CHALLENGE 1 =================
 * This challenge consists of 50 equal sized words
 * Lower cased and without any accents
 * One input and one possible answer
 */

/**
 * ----------- ANAGRAM CHALLENGE 1 SOLVER 1 -------------
 */
char abc[] = "abcdefghijklmnopqrstuvwxyz";
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
                47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

int _map_primes(char c)
{
    for (size_t i = 0; i < 26; i++)
    {
        if (c == abc[i])
        {
            return primes[i];
        }
    }
}

/* anagram_1_solver_1 a solver for the first challenge */
char *anagram_1_solver_1(char **dict, int dict_word_n, char *input, int word_size)
{
    size_t i = 0, j = 0;
    char *solution = NULL;
    int solution_prod = 1, aux_prod = 1;

    for (i = 0; i < word_size; i++)
    {
        solution_prod = solution_prod * _map_primes(input[i]);
    }

    for (i = 0; i < dict_word_n; i++)
    {
        aux_prod = 1;
        j = 0;

        while (dict[i][j] != '\0')
        {
            aux_prod = aux_prod * _map_primes(dict[i][j]);
            j++;
        }

        if (aux_prod == solution_prod)
        {
            solution = dict[i];
            break;
        }
    }

    return solution;
}

/**
 * ----------- ANAGRAM CHALLENGE 1 SOLVER 2 -------------
 */
/* anagram_1_solver_2 a solver for the first challenge */
char *anagram_1_solver_2(char **dict, int dict_word_n, char *input, int word_size)
{
    return NULL;
}

/**
 * ================ ANAGRAM CHALLENGE 2 =================
 * This challenge consists of 50 different sized words
 * Lower cased and without any accents
 * One input and one possible answer
 */

/**
 * ----------- ANAGRAM CHALLENGE 2 SOLVER 1 -------------
 */
/* anagram_2_solver_1 a solver for the second challenge */
char *anagram_2_solver_1(char **dict, int dict_word_n, char *input, int word_size)
{
    return NULL;
}
