// std lib imports - the only ones allowed!
#include <stdio.h>
#include <stdlib.h>

// import your own headers
#include "iohelper.h"

/* dict_reader */
char **dict_reader(char **dict, const char *filename, int dict_size)
{
    FILE *f = NULL;
    char buf[50];
    size_t i = 0, j = 0, n = 0;

    // open the dict file
    f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("[ERROR] Dict could not be open at %s!\n", filename);
        dict_disposer(dict, dict_size);
        return NULL;
    }

    while (fgets(buf, 50, f) != NULL)
    {
        // find word size
        for (i = 0; i < 50; i++)
        {
            if (buf[i] == '\n' || buf[i] == '\0' || buf[i] == '\r')
            {
                break;
            }
        }
        // only allocate it if we actually can!
        if (n >= dict_size)
        {
            printf("[ERROR] There are more lines than %d in this file!\n", dict_size);
            dict_disposer(dict, dict_size);
            return NULL;
        }

        dict[n] = (char *)malloc(sizeof(char) * (i + 1));
        if (dict[n] == NULL)
        {
            printf("[ERROR] There was an error allocating memory for a word in the dict\n");
            dict_disposer(dict, dict_size);
            return NULL;
        }

        // terminate the string
        dict[n][i] = '\0';
        // and print it onto our dict
        for (j = i; j > 0; j--)
        {
            dict[n][j - 1] = buf[j - 1];
        }

        // and iterate to next word
        n++;
    }

    fclose(f);

    return dict;
}

/* disposer */
void dict_disposer(char **dict, int n)
{
    size_t i;
    for (i = 0; i < n; i++)
    {
        if (dict[i] != NULL)
        {
            free(dict[i]);
        }
    }
    free(dict);
}