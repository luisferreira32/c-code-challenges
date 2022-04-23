// external libs
#include <stdio.h>
#include <string.h>

// include all challenge libs to be able to call this runner freely
#include "anagram.h"

void print_helper()
{
  printf("[INFO] No sufficient arguments were given:\n");
  printf("       --ch     --challenge is the name and version of the\n");
  printf("                challenge you want to run, e.g., anagram1 \n");
  printf("       --sv     --solver is the name of the solver for the\n");
  printf("                challenge solver to run, e.g. solver1 \n");
  printf("       --help   to see this man page again\n");
}

int main(int argc, const char *argv[])
{
  // check for pre conditions
  if (argc < 5)
  {
    print_helper();
    return 0;
  }

  const char *challenge_name = NULL, *solver_name = NULL;
  for (size_t i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "--help") == 0)
    {
      print_helper();
      return 0;
    }
    if (strcmp(argv[i], "--ch") == 0 || strcmp(argv[i], "--challenge") == 0)
    {
      if (i + 1 > argc - 1)
      {
        print_helper();
        return 0;
      }
      challenge_name = argv[i + 1];
    }
    if (strcmp(argv[i], "--sv") == 0 || strcmp(argv[i], "--solver") == 0)
    {
      if (i + 1 > argc - 1)
      {
        print_helper();
        return 0;
      }
      solver_name = argv[i + 1];
    }
  }
  if (challenge_name == NULL || solver_name == NULL)
  {
    print_helper();
    return 0;
  }

  // run the requested challenge
  if (strcmp(challenge_name, "anagram1") == 0)
  {
    anagram_challenge_runner(ANAGRAM_1_DICT_PATH, ANAGRAM_1_WORD_N, ANAGRAM_1_INPUT, ANAGRAM_1_SOLUTION, ANAGRAM_1_INPUT_SIZE, solver_name);
    printf("[INFO] Finished the running the %s challenge...\n", challenge_name);
  }
  else if (strcmp(challenge_name, "anagram2") == 0)
  {
    anagram_challenge_runner(ANAGRAM_2_DICT_PATH, ANAGRAM_2_WORD_N, ANAGRAM_2_INPUT, ANAGRAM_2_SOLUTION, ANAGRAM_2_INPUT_SIZE, solver_name);
    printf("[INFO] Finished the running the %s challenge...\n", challenge_name);
  }

  return 0;
}
