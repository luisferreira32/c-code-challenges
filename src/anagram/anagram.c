// external libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// import your own headers
#include "anagram.h"
#include "solver1.h"

// Just doing some tests +1
// and your own helper functions
#include "quicksort.h"
#include "iohelper.h"

const static struct
{
    const char *solver_name;
    char *(*solver)(char **, int, char *, int);
} solver_map[] = {
    {"solver1", solver1},
    // add your solvers to the mapper
};
const int solver_n = 1;

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

    // and now *shuffle* a bit!

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

/* anagram challenge runner */
int anagram_challenge_runner(const char *dict_path, int dict_word_n, char *input, char *solution, int word_size, const char *solver)
{
    char **dict = NULL;
    char *result = NULL;
    int error = 0;

    dict = anagram_dict_loader(dict_path, dict_word_n);
    if (dict == NULL)
    {
        printf("[WARNING] Failed to load dict for challenge %s...\n", solver);
        return 1;
    }

    for (size_t i = 0; i < solver_n; i++)
    {
        if (strcmp(solver_map[i].solver_name, solver) == 0)
        {
            result = solver_map[i].solver(dict, dict_word_n, input, word_size);
            if (result == NULL)
            {
                printf("[WARNING] Didn't receive any result from solver %s?\n", solver);
                error = 1;
            }
            else if (strcmp(result, solution) == 0)
            {
                printf("[INFO] You reached the right result with %s!\n", solver);
            }
            else
            {
                printf("[INFO] You FAILED to reach the right result with %s...\n", solver);
                error = 1;
            }
            break;
        }

        if (result == NULL)
        {
            printf("[WARNING] Solver %s is not mapped.\n", solver);
        }
    }
    anagram_dict_disposer(dict, ANAGRAM_1_WORD_N);

    return error;
}

