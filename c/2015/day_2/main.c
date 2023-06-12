#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define AOCYEAR 2015
#define AOCDAY 2

int find_surface_area(int width, int height, int length);
int find_smallest_side(int width, int height, int length);
int find_smallest_perimeter(int width, int height, int length);

int main()
{
  int width, height, length;
  int paper_quantity = 0;
  int ribbon_quantity = 0;
  while (scanf("%dx%dx%d", &width, &height, &length) == 3)
  {
    paper_quantity += find_surface_area(width, height, length);
    paper_quantity += find_smallest_side(width, height, length);
    ribbon_quantity += width * height * length;
    ribbon_quantity += find_smallest_perimeter(width, height, length);
  }
  printf("%4d-%02d/%d: %d\n", AOCYEAR, AOCDAY, 1, paper_quantity);
  printf("%4d-%02d/%d: %d\n", AOCYEAR, AOCDAY, 2, ribbon_quantity);

  return 0;
}

int find_surface_area(int width, int height, int length)
{
  return 2 * width * height + 2 * width * length + 2 * height * length;
}

int find_smallest_side(int width, int height, int length)
{
  int x = width * height;
  int y = width * length;
  int z = height * length;

  return x > y ? (y > z ? z : y) : (x > z ? z : x);
}

int find_smallest_perimeter(int width, int height, int length)
{
  int x = 2 * width + 2 * height;
  int y = 2 * width + 2 * length;
  int z = 2 * height + 2 * length;

  return x > y ? (y > z ? z : y) : (x > z ? z : x);
}
