#include <stdio.h>

int get_fibonacci_last_digit(int n) 
{
  int curent, penultim = 0, ultim = 1, index;
  if(n <= 1)
    return n;
  else for(index = 2; index <= n; index ++)
  {
    curent = (ultim + penultim) % 10;
    penultim = ultim;
    ultim = curent;
  }
  return curent;
}

int main()
{
  int n;
  scanf("%d", &n);
  int c = get_fibonacci_last_digit(n);
  printf("%d\n", c);
}
