// external libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// import your own headers
#include "anagram.h"
#include "solver1.h"

// Just doing some tests +1
// and your own helper functions
#include "quicksort.h"
#include "iohelper.h"

/*
 * Input mapping for anagram challenges
 */
AnagramInput an_input_map[2] = {
    {ANAGRAM_1_DICT_PATH, ANAGRAM_1_WORD_N, ANAGRAM_1_INPUT, ANAGRAM_1_INPUT_SIZE, ANAGRAM_1_SOLUTION},
    {ANAGRAM_2_DICT_PATH, ANAGRAM_2_WORD_N, ANAGRAM_2_INPUT, ANAGRAM_2_INPUT_SIZE, ANAGRAM_2_SOLUTION},
};

/*
 * Solver mapping for anagram challenges
 */
const static struct
{
    const char *solver_name;
    char *(*solver)(char **, int, char *, int);
} an_solver_map[] = {
    {"solver1", an_solver1},
    // add your solvers to the mapper
};

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
int anagram_challenge_runner(int challenge_n, const char *solver, clock_t *timer)
{
    if (challenge_n > AN_INPUT_N)
    {
        printf("[WARNING] Failed to load input for challenge anagram%d...\n", challenge_n);
        return 1;
    }
    challenge_n--; // indexing actually starts at zero ;)

    char **dict = NULL;
    char *result = NULL;
    int error = 0;
    clock_t start_t, end_t;

    dict = anagram_dict_loader(an_input_map[challenge_n].dict_path, an_input_map[challenge_n].dict_word_n);
    if (dict == NULL)
    {
        printf("[WARNING] Failed to load dict for challenge anagram%d...\n", challenge_n);
        return 1;
    }

    for (size_t i = 0; i < AN_SOLVER_N; i++)
    {
        if (strcmp(an_solver_map[i].solver_name, solver) == 0)
        {
            /*
             * ===== IMPORTANT =====
             * We have to wrap the timer around our solver run to return in to main.
             * But give it a couple repetitions to get a nicer sum of running times.
             */

            // timer start
            start_t = clock();
            for (size_t j = 0; j < AN_REPETITIONS; j++)
            {
                result = an_solver_map[i].solver(dict, an_input_map[challenge_n].dict_word_n, an_input_map[challenge_n].input_word, an_input_map[challenge_n].input_size);
            }
            end_t = clock();
            // timer end

            *timer = end_t - start_t;
            if (result == NULL)
            {
                printf("[WARNING] Didn't receive any result from solver %s?\n", solver);
                error = 1;
            }
            else if (strcmp(result, an_input_map[challenge_n].solution) == 0)
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

        if (result == NULL && i + 1 == AN_SOLVER_N)
        {
            printf("[WARNING] Solver %s is not mapped.\n", solver);
            error = 1;
        }
    }
    anagram_dict_disposer(dict, an_input_map[challenge_n].dict_word_n);

    return error;
}
