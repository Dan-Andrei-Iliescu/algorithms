#include <stdio.h>

int gcd(int a, int b)
{
  int rest = 1;
  while(rest != 0)
  {
    rest = a % b;
    a = b;
    b = rest;
  }
  return a;
}

int main()
{
  int a, b, r;
  scanf("%d%d", &a, &b);
  
  r = gcd(a, b);
  printf("%d\n", r);
  return 0;
}
