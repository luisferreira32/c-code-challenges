// std lib imports - the only ones allowed!
#include <stdlib.h>
#include <stdio.h>

// import your own headers
#include "solver1.h"

char *wi_solver1(char *input, int input_size)
{
    char *result = NULL;
    int word_b = 0, result_p = input_size;
    size_t i, j;

    // initialization
    result = (char *)malloc((input_size + 1) * sizeof(char));
    if (result == NULL)
    {
        printf("[ERROR] unexpected error allocating memory.");
        return NULL;
    }
    for (i = 0; i < input_size; i++)
    {
        result[i] = ' ';
    }
    result[input_size] = '\0';

    // word skewing
    for (i = 0; i < input_size; i++)
    {
        // at each space, we have a word
        if (input[i] == ' ')
        {
            result[i - word_b] = ' ';
            result_p = input_size - i;
            for (j = word_b; j < i; j++)
            {
                result[result_p] = input[j];
                result_p++;
            }
            word_b = i + 1;
        }
    }

    // last word is a special case, there might not be any spaces
    result_p = input_size - i;
    for (j = word_b; j < i; j++)
    {
        result[result_p] = input[j];
        result_p++;
    }

    for (size_t i = 0; i < input_size; i++)
    {
        input[i] = result[i];
    }
    free(result);

    return input;
}