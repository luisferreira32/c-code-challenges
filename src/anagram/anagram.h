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
 * This function runs an anagram challenge
 */
void anagram_challenge_runner(const char *, int, char *, char *, int, const char *);

/**
 * ================ ANAGRAM CHALLENGE 1 =================
 */

/**
 * This challenge consists of 50 equal sized words
 * Lower cased and without any accents
 * One input and one possible answer
 */
#define ANAGRAM_1_DICT_PATH "src/anagram/anagram_1.dict"
#define ANAGRAM_1_WORD_N 50
#define ANAGRAM_1_INPUT "least"
#define ANAGRAM_1_INPUT_SIZE 5
#define ANAGRAM_1_SOLUTION "steal"

/**
 * ================ ANAGRAM CHALLENGE 2 =================
 */

/**
 * This challenge consists of 50 different sized words
 * Lower cased and without any accents
 * One input and one possible answer
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