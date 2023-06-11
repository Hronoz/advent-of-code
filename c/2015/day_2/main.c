#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  int i = 0, x, y, z;
  char input[10000];
  char *cp, *token;

  scanf("%[^;]s", input);
  cp = strdup(input);
  token = strtok(cp, "x");
  printf("%s\n", token);
  while ((token = strtok(NULL, "x")) != NULL)
  {
    printf("%s\n", token);
  }
  return 0;
}
