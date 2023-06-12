#include <stdio.h>
#include <stdbool.h>

#define AOCYEAR 2015
#define AOCDAY  1

int main()
{
  int ch;
  int floor = 0, basement_pos = 0;
  bool in_basement = false;

  while((ch = getchar()) != EOF)
  {
    if (ch == '(') floor++;
    else if (ch == ')') floor--;
    
    if (!in_basement) { basement_pos++; }
    if (!in_basement && floor < 0) { in_basement = true; }
  }

  printf("%4d-%02d/%d: %d\n", AOCYEAR, AOCDAY, 1, floor);
  printf("%4d-%02d/%d: %d\n", AOCYEAR, AOCDAY, 2, basement_pos);

  return 0;
}
