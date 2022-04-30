#ifndef WORDINVERSION_H
#define WORDINVERSION_H

/* Definition of common structs */
typedef struct
{
    char *input;
    int input_size;
    char *solution;
} WordInversionInput;

/* and common macros */
#define WI_REPETITIONS 1
#define WI_INPUT_N 3
#define WI_SOLVER_N 2

/**
 * ===================== HELPER FUNCTIONS =====================
 * These are helper functions for the wordinversion challenge
 */

/**
 * This function runs an wordinversion challenge
 */
int wordinversion_challenge_runner(int, const char *, clock_t *);

/**
 * ================ WORDINVERSION CHALLENGE 1 =================
 */

/**
 * The simplest case.
 */
#define WORDINVERSION_1_SENTENCE "Hello world"
#define WORDINVERSION_1_INPUT_SIZE 11
#define WORDINVERSION_1_SOLUTION "world Hello"

/**
 * ================ WORDINVERSION CHALLENGE 2 =================
 */

/**
 * Some spaces at the end really mess you up? Unlucky 13...
 */
#define WORDINVERSION_2_SENTENCE "Hello world  "
#define WORDINVERSION_2_INPUT_SIZE 13
#define WORDINVERSION_2_SOLUTION "  world Hello"

/**
 * ================ WORDINVERSION CHALLENGE 3 =================
 */

/**
 * Just a bit longer than usual
 */
#define WORDINVERSION_3_SENTENCE "Hello world it is me mario"
#define WORDINVERSION_3_INPUT_SIZE 26
#define WORDINVERSION_3_SOLUTION "mario me is it world Hello"

#endif /* WORDINVERSION_H */