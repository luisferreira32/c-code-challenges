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
  }

  for (size_t i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "anagram_mock") == 0)
    {
      anagram_mock();
    }
  }

  printf("[INFO] Finished the %s challenge...\n", argv[1]);
  return 0;
}
