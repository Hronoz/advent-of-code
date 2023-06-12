#include <stdio.h>

#define AOCYEAR 2015
#define AOCDAY 3

#define MAXSIZE 512

int main()
{
  int ch, i, j;
  int board[MAXSIZE][MAXSIZE] = { 0 };
  int x = 128, y = 128, result = 0;

  while ((ch = getc(stdin)) != EOF)
  {
    switch (ch)
    {
      case 'v':
        y--;
        break;
      case '<':
        x--;
        break;
      case '>':
        x++;
        break;
      case '^':
        y++;
        break;
    }
    
    board[y][x] += 1;
  }

  for (i = 0; i < MAXSIZE; ++i)
    for (j = 0; j < MAXSIZE; ++j)
    {
      result += (board[i][j] > 0 ? 1 : 0);
    }
  printf("%4d-%02d/%d: %d\n", AOCYEAR, AOCDAY, 1, result);

  return 0;
}
