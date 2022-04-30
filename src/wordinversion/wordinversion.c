// external libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// import your own headers
#include "wordinversion.h"
#include "solver1.h"
#include "solver2.h"

/*
 * Input mapping for wordinversion challenges
 */
WordInversionInput wi_input_map[3] = {
    {WORDINVERSION_1_SENTENCE, WORDINVERSION_1_INPUT_SIZE, WORDINVERSION_1_SOLUTION},
    {WORDINVERSION_2_SENTENCE, WORDINVERSION_2_INPUT_SIZE, WORDINVERSION_2_SOLUTION},
    {WORDINVERSION_3_SENTENCE, WORDINVERSION_3_INPUT_SIZE, WORDINVERSION_3_SOLUTION},
};

/*
 * Solver mapping for wordinversion challenges
 */
const static struct
{
    const char *solver_name;
    char *(*solver)(char *, int);
} wi_solver_map[] = {
    {"solver1", wi_solver1},
    {"solver2", wi_solver2},
    // add your solvers to the mapper
};

/**
 * ===================== HELPER FUNCTIONS =====================
 * These are helper functions for the wordinversion challenge
 */

/* wordinversion challenge runner */
int wordinversion_challenge_runner(int challenge_n, const char *solver, clock_t *timer)
{
    if (challenge_n > WI_INPUT_N)
    {
        printf("[WARNING] Failed to load input for challenge wordinversion%d...\n", challenge_n);
        return 1;
    }
    challenge_n--; // indexing actually starts at zero ;)

    int error = 0;
    char *result = NULL, *input = NULL;
    clock_t start_t, end_t;

    // init input for the solvers to be able to use it (macros are not writable)
    input = (char *)malloc(sizeof(char) * (wi_input_map[challenge_n].input_size + 1));
    if (input == NULL)
    {
        printf("[ERROR] unexpected error allocating memory for input.");
        return 1;
    }
    input[wi_input_map[challenge_n].input_size] = '\0';
    if (strcpy(input, wi_input_map[challenge_n].input) == NULL)
    {
        free(input);
        printf("[ERROR] unexpected error copying input to its memory.");
        return 1;
    }

    // pick up the correct solver
    for (size_t i = 0; i < WI_SOLVER_N; i++)
    {
        if (strcmp(wi_solver_map[i].solver_name, solver) == 0)
        {
            /*
             * ===== IMPORTANT =====
             * We have to wrap the timer around our solver run to return in to main.
             * But give it a couple repetitions to get a nicer sum of running times.
             */

            // timer start
            start_t = clock();
            for (size_t j = 0; j < WI_REPETITIONS; j++)
            {
                result = wi_solver_map[i].solver(input, wi_input_map[challenge_n].input_size);
            }
            end_t = clock();
            // timer end

            *timer = end_t - start_t;
            if (result == NULL)
            {
                printf("[WARNING] Didn't receive any result from solver %s?\n", solver);
                error = 1;
            }
            else if (strcmp(result, wi_input_map[challenge_n].solution) == 0)
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

        if (result == NULL && i + 1 == WI_SOLVER_N)
        {
            printf("[WARNING] Solver %s is not mapped.\n", solver);
            error = 1;
        }
    }

    free(input);
    return error;
}
