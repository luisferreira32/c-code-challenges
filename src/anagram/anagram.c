// std lib imports - the only ones allowed!
#include <stdio.h>
#include <stdlib.h>

// import your own headers
#include "anagram.h"

// and your own functions
#include "quicksort.h"
#include "iohelper.h"

/* anagram challenge runner mock */
void anagram_mock()
{
    printf("[INFO] Anagram mock has ran!\n");
    quicksort_mock();
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