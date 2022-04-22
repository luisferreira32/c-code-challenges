#ifndef ANAGRAM_H
#define ANAGRAM_H

/**
 * This is a mock implementation of the anagram challenge
 * It won't do anything!
 */
void anagram_mock();

/**
 * ================== HELPER FUNCTIONS ==================
 * These are helper functions for the anagram challenge
 */

/**
 * This function loads the anagram dict onto a char **
 */
char **anagram_dict_loader(const char *, int);
/**
 * This function disposes of the anagram dict
 */
void anagram_dict_disposer(char **, int);

/**
 * ================ ANAGRAM CHALLENGE 1 =================
 */

/**
 * This is the first anagram challenge with a first solver
 * It is a specific challenge - so you can solve it specifically
 * to get better times? Go to the bit!
 */
#define ANAGRAM_1_DICT_PATH "src/anagram/anagram_1.dict"
#define ANAGRAM_1_WORD_N 50
#define ANAGRAM_1_INPUT "least"
#define ANAGRAM_1_INPUT_SIZE 5
#define ANAGRAM_1_SOLUTION "steal"

/**
 * This is the first solver for the first anagram challenge
 * It is a specific challenge with a generic solver, so
 * it can only improve from now on :)
 */
char *anagram_1_solver_1(char **, int, char *, int);

/**
 * Empty solver slot
 */
char *anagram_1_solver_2(char **, int, char *, int);

/**
 * ================ ANAGRAM CHALLENGE 1 =================
 */

/**
 * This is the first anagram challenge with a first solver
 * It is a specific challenge - so you can solve it specifically
 * to get better times? Go to the bit!
 */
#define ANAGRAM_2_DICT_PATH "src/anagram/anagram_2.dict"
#define ANAGRAM_2_WORD_N 50
#define ANAGRAM_2_INPUT "car"
#define ANAGRAM_2_INPUT_SIZE 3
#define ANAGRAM_2_SOLUTION "arc"

/**
 * Empty solver slot
 */
char *anagram_2_solver_1(char **, int, char *, int);

#endif /* ANAGRAM_H */