// std lib imports - the only ones allowed!
#include <stdlib.h>
#include <stdio.h>

// import your own headers
#include "solver2.h"

void *_w_inv(char *str, int w_b, int w_e)
{
    char x;
    for (size_t i = w_b; i < w_e; i++)
    {
        if (i - w_b >= ((w_e - w_b) / 2))
        {
            break;
        }
        x = str[i];
        str[i] = str[w_e - i - 1];
        str[w_e - i - 1] = x;
        printf("_w_inv %d %d==%s==\n", w_b, w_e, str);
    }
}

char *wi_solver2(char *input, int input_size)
{
    char x;
    int left_p = 0, right_p = input_size;
    size_t i, j;

    // stencen inverting
    for (i = 0; i < input_size; i++)
    {
        if (i >= input_size / 2)
        {
            break;
        }
        // space on the left hand side
        if (input[i] == ' ')
        {
            _w_inv(input, left_p, i);
            left_p = i + 1;
        }
        // space on the right hand side
        if (input[input_size - i - 1] == ' ')
        {
            _w_inv(input, input_size - i - 1, right_p);
            right_p = input_size - i - 2;
        }

        // swap characters
        x = input[i];
        input[i] = input[input_size - i - 1];
        input[input_size - i - 1] = x;
        printf("==%s==\n", input);
    }

    return input;
}