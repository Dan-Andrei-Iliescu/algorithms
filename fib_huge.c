#include <stdio.h>

long long fib[999999];

long long find_period(long long m)
{
  long long index = 1;
  short ok = 0;
  
  fib[0] = 0;
  fib[1] = 1;
  
  while(fib[index] != 1 || fib[index - 1] != 0 || ok == 0)
  {
    index ++;
    
    fib[index] = (fib[index - 1] + fib[index - 2]) % m;
    
    ok = 1;
  }
  
  return index - 1;
}

int main()
{  
  long long n, m;
  scanf("%llu %llu", &n, &m);
  
  long long period = find_period(m);
  
  n = n % period;
  
  printf("%llu\n", fib[n]);
  
  return 0;
}
