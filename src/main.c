#include <stdio.h>

int main(int argc, const char *argv[])
{
  if (argc < 2)
  {
    printf("[INFO] Give at least a challenge to run as input!\n");
    return 0;
  }

  printf("[INFO] Finished the %s challenge...\n", argv[1]);
  return 0;
}
