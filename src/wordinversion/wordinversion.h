#ifndef WORDINVERSION_H
#define WORDINVERSION_H

/* and common macros */
#define REPETITIONS 10000

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
#define WORDINVERSION_1_SOLUTION "world Hello"

/**
 * ================ WORDINVERSION CHALLENGE 2 =================
 */

/**
 * Some spaces at the end really mess you up?
 */
#define WORDINVERSION_2_SENTENCE "Hello world  "
#define WORDINVERSION_2_SOLUTION "world Hello  "

#endif /* WORDINVERSION_H */