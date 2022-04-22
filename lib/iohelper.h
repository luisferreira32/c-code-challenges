#ifndef IOHELPER_H
#define IOHELPER_H

/**
 * Reads a dict and sends it to an array of pointers
 * - arg1: pointer to a list of pointers
 * - arg2: the filename
 * - arg3: the number of words in the dict
 * Returns: size of the array or error -1
 * WARNING: it mallocs memory for you, don't forget to free
 * WARNING: if the dict is not long enough it returns null
 * WARNING: if a word exceeds 50 characters it won't be read
 */
char **dict_reader(char **, const char *, int);

/**
 * Reads a dict and sends it to an array of pointers
 * - arg1: pointer to a list of pointers
 * - arg2: the number of words in the dict
 * WARNING: it mallocs memory for you, don't forget to free
 */
void dict_disposer(char **, int);

#endif /* IOHELPER_H */