#include <stdio.h>

int min_2(int a, int b)
{
  return (a < b) ? a : b;
}

int min_3(int a, int b, int c)
{
  if(a < b)
    if(a < c) return a;
    else return c;
  else if(b < c) return b;
  else return c;
}

int main()
{
  int number, sol[1000001], array[1000001], index;
  
  scanf("%d", &number);
  
  sol[1] = 0;
  
  // Find solution
  for(index = 2; index <= number; index ++)
    if(index % 6 == 0)
      sol[index] = 1 + min_3(sol[index / 3], sol[index / 2], sol[index - 1]);
    else if(index % 3 == 0)
      sol[index] = 1 + min_2(sol[index / 3], sol[index - 1]);
    else if(index % 2 == 0)
      sol[index] = 1 + min_2(sol[index / 2], sol[index - 1]);
    else sol[index] = 1 + sol[index - 1];
    
  printf("%d\n", sol[number]);
  
  // Reconstruct solution
  index = number;
  array[sol[index]] = number;
  while(index > 1)
  {
    if(index % 3 == 0 && sol[index] == sol[index / 3] + 1)
      index /= 3;
    else if(index % 2 == 0 && sol[index] == sol[index / 2] + 1)
      index /= 2;
    else index -= 1;
    
    array[sol[index]] = index;
  }
  
  for(index = 0; index <= sol[number]; index ++)
    printf("%d ", array[index]);
  
  return 0;
}
