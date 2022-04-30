// external libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

// include all challenge libs to be able to call this runner freely
#include "anagram.h"
#include "wordinversion.h"

void print_helper()
{
  printf("[INFO] No sufficient arguments were given:\n");
  printf("       --ch     --challenge is the name and version of the\n");
  printf("                challenge you want to run, e.g., anagram1 \n");
  printf("       --sv     --solver is the name of the solver for the\n");
  printf("                challenge solver to run, e.g. solver1 \n");
  printf("       --help   to see this man page again\n");
}

const static struct
{
  char *challenge_name;
  int (*challenge_runner)(int, const char *, clock_t *);
} challenge_map[] = {
    {"anagram", anagram_challenge_runner},
    {"wordinversion", wordinversion_challenge_runner},
    // add your challenge runners to the mapper
};
const int challenge_n = 2;

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
  int error = 0, challenge_version = 1, i = 0;
  char challenge_name_prunned[50];
  clock_t timer;

  for (i = 0; challenge_name[i] != '\0'; i++)
  {
  }
  challenge_version = atoi(&challenge_name[i - 1]);
  if (challenge_version == 0)
  {
    printf("[WARNING] Challenge version should not be zero, exiting now...\n");
    return 1;
  }

  if (i >= 50)
  {
    printf("[WARNING] Keep challenge names under 50 chars, exiting now...\n");
    return 1;
  }

  if (strcpy(challenge_name_prunned, challenge_name) == NULL)
  {
    printf("[ERROR] Unexpected error! Failed to get the challenge name.\n");
    return 1;
  }

  challenge_name_prunned[i - 1] = '\0';

  for (size_t i = 0; i < challenge_n; i++)
  {
    if (strcmp(challenge_map[i].challenge_name, challenge_name_prunned) == 0)
    {
      error = challenge_map[i].challenge_runner(challenge_version, solver_name, &timer);
      break;
    }
    else if (i + 1 == challenge_n)
    {
      printf("[WARNING] Given challenge %s was not in the database...\n", challenge_name);
      error = 1;
    }
  }

  if (error)
  {
    fprintf(stderr, "[ERROR] Error running challenge %s!\n", challenge_name);
  }
  else
  {
    printf("[INFO] Challenge %s successfully ran. Total clocks taken by CPU: %lu\n", challenge_name, timer);
  }

  return error;
}
