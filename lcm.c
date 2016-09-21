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

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  
  int g = gcd(a, b);
  
  printf("%llu \n", (long long) a * b / g);
  return 0;
}
