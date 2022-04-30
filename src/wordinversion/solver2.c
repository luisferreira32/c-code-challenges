// std lib imports - the only ones allowed!
#include <stdlib.h>
#include <stdio.h>

// import your own headers
#include "solver2.h"

void *_w_inv(char *str, int w_b, int w_e)
{
    char x;
    int deviation;
    for (size_t i = w_b; i < w_e; i++)
    {
        deviation = i - w_b;
        if (i - w_b >= ((w_e - w_b) / 2))
        {
            break;
        }
        x = str[i];
        str[i] = str[w_e - deviation - 1];
        str[w_e - deviation - 1] = x;
    }
}

char *wi_solver2(char *input, int input_size)
{
    char x;
    size_t i = 0, j = 0;

    // sentence inverting
    for (i = 0; i < input_size; i++)
    {
        if (i >= input_size / 2)
        {
            break;
        }
        // swap characters
        x = input[i];
        input[i] = input[input_size - i - 1];
        input[input_size - i - 1] = x;
    }

    // invert all words but the last
    for (i = 0; i < input_size; i++)
    {
        if (input[i] == ' ')
        {
            _w_inv(input, j, i);
            j = i + 1;
        }
    }
    // and the last
    _w_inv(input, j, i);

    return input;
}
