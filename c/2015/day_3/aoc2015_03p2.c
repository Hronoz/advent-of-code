#include <stdio.h>
#include <stdbool.h>

#define AOCYEAR 2015
#define AOCDAY 3

#define MAXSIZE 512

int main()
{
  int ch, i, j;
  int board[MAXSIZE][MAXSIZE] = { 0 };
  int x_santa = 256, y_santa = 256, result = 0;
  int x_robot = 256, y_robot = 256;

  bool robots_turn = false;

  while ((ch = getc(stdin)) != EOF)
  {
    switch (ch)
    {
      case 'v':
        if (robots_turn)
          y_robot--;
        else 
          y_santa--;
        break;
      case '<':
        if (robots_turn)
          x_robot--;
        else 
          x_santa--;
        break;
      case '>':
        if (robots_turn)
          x_robot++;
        else
          x_santa++;
        break;
      case '^':
        if (robots_turn)
          y_robot++;
        else
          y_santa++;
        break;
    }
    
    if (robots_turn)
      board[y_robot][x_robot] += 1;
    else
      board[y_santa][x_santa] += 1;

    robots_turn = !robots_turn;
  }

  for (i = 0; i < MAXSIZE; ++i)
    for (j = 0; j < MAXSIZE; ++j)
    {
      result += (board[i][j] > 0 ? 1 : 0);
    }
  printf("%4d-%02d/%d: %d\n", AOCYEAR, AOCDAY, 2, result);

  return 0;
}
