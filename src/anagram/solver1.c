// std lib imports - the only ones allowed!
#include <stdlib.h>

// import your own headers
#include "solver1.h"

/* helper code */
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

/* solver1 for the anagram challenge */
char *solver1(char **dict, int dict_word_n, char *input, int word_size)
{
    size_t i = 0, j = 0;
    char *solution = NULL;
    long int solution_prod = 1, aux_prod = 1;

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

    return NULL;
}