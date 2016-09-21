#include <stdio.h>

int main()
{
  int number;
  scanf("%d", &number);
  
  int penultimul = 0, ultimul = 1, curent, index;
  if(number <= 1)
    curent = number;
  else for(index = 2; index <= number; index ++)
  {
    curent = ultimul + penultimul;
    penultimul = ultimul;
    ultimul = curent;
  }
  
  printf("%d\n", curent);
  return 0;
}
