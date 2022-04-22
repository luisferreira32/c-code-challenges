// external libs
#include <stdio.h>
#include <string.h>

// include all challenge libs to be able to call this runner freely
#include "anagram.h"

int main(int argc, const char *argv[])
{
  if (argc < 2)
  {
    printf("[INFO] About to run all challenges!\n");
    anagram_mock();
    printf("[INFO] No challenge selected with argv\n");
    return 0;
  }

  for (size_t i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "anagram_mock") == 0)
    {
      anagram_mock();
      printf("[INFO] Finished the %s challenge...\n", argv[i]);
    }
    else if (strcmp(argv[i], "anagram_1_solver_1") == 0)
    {
      char **dict = NULL;
      char *solution = NULL;

      dict = anagram_dict_loader(ANAGRAM_1_DICT_PATH, ANAGRAM_1_WORD_N);
      if (dict == NULL)
      {
        printf("[WARNING] Failed to load dict for challenge %s...\n", argv[i]);
        break;
      }

      solution = anagram_1_solver_1(dict, ANAGRAM_1_WORD_N, ANAGRAM_1_INPUT, ANAGRAM_1_INPUT_SIZE);
      if (solution == NULL)
      {
        printf("[INFO] Didn't receive any solution from solver %s?\n", argv[i]);
      }
      else if (strcmp(solution, ANAGRAM_1_SOLUTION) == 0)
      {
        printf("[INFO] You reached the right solution with %s!\n", argv[i]);
      }
      else
      {
        printf("[INFO] You FAILED to reach the right solution with %s...\n", argv[i]);
      }

      printf("[INFO] Finished the %s challenge...\n", argv[i]);

      anagram_dict_disposer(dict, ANAGRAM_1_WORD_N);
    }
    else if (strcmp(argv[i], "anagram_1_solver_2") == 0)
    {
      char **dict = NULL;
      char *solution = NULL;

      dict = anagram_dict_loader(ANAGRAM_1_DICT_PATH, ANAGRAM_1_WORD_N);
      if (dict == NULL)
      {
        printf("[WARNING] Failed to load dict for challenge %s...\n", argv[i]);
        break;
      }

      solution = anagram_1_solver_2(dict, ANAGRAM_1_WORD_N, ANAGRAM_1_INPUT, ANAGRAM_1_INPUT_SIZE);
      if (solution == NULL)
      {
        printf("[INFO] Didn't receive any solution from solver %s?\n", argv[i]);
      }
      else if (strcmp(solution, ANAGRAM_1_SOLUTION) == 0)
      {
        printf("[INFO] You reached the right solution with %s!\n", argv[i]);
      }
      else
      {
        printf("[INFO] You FAILED to reach the right solution with %s...\n", argv[i]);
      }

      printf("[INFO] Finished the %s challenge...\n", argv[i]);

      anagram_dict_disposer(dict, ANAGRAM_1_WORD_N);
    }
    else if (strcmp(argv[i], "anagram_2_solver_1") == 0)
    {
      char **dict = NULL;
      char *solution = NULL;

      dict = anagram_dict_loader(ANAGRAM_2_DICT_PATH, ANAGRAM_2_WORD_N);
      if (dict == NULL)
      {
        printf("[WARNING] Failed to load dict for challenge %s...\n", argv[i]);
        break;
      }

      solution = anagram_2_solver_1(dict, ANAGRAM_2_WORD_N, ANAGRAM_2_INPUT, ANAGRAM_2_INPUT_SIZE);
      if (solution == NULL)
      {
        printf("[INFO] Didn't receive any solution from solver %s?\n", argv[i]);
      }
      else if (strcmp(solution, ANAGRAM_2_SOLUTION) == 0)
      {
        printf("[INFO] You reached the right solution with %s!\n", argv[i]);
      }
      else
      {
        printf("[INFO] You FAILED to reach the right solution with %s...\n", argv[i]);
      }

      printf("[INFO] Finished the %s challenge...\n", argv[i]);

      anagram_dict_disposer(dict, ANAGRAM_2_WORD_N);
    }
  }

  printf("[INFO] Finished running the given challenges!...\n");
  return 0;
}
