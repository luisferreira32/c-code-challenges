#ifndef ANAGRAM_H
#define ANAGRAM_H

/* Definition of common structs */
typedef struct
{
    const char *dict_path;
    int dict_word_n;
    char *input_word;
    int input_size;
    char *solution;
} Input;

/* and common macros */
#define REPETITIONS 10000

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
int anagram_challenge_runner(int, const char *, clock_t *);

/**
 * ================ ANAGRAM CHALLENGE 1 =================
 */

/**
 * This challenge consists of 50 equal sized words
 * Lower cased and without any accents
 * One input and one possible answer
 */
#define ANAGRAM_1_DICT_PATH "src/anagram/anagram1.dict"
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
#define ANAGRAM_2_DICT_PATH "src/anagram/anagram2.dict"
#define ANAGRAM_2_WORD_N 50
#define ANAGRAM_2_INPUT "car"
#define ANAGRAM_2_INPUT_SIZE 3
#define ANAGRAM_2_SOLUTION "arc"

#endif /* ANAGRAM_H */