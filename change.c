#include<stdio.h>

int get_change(int m)
{
  int no_coins = 0;
  
  // No of 10s
  while(m >= 10)
  {
    m = m - 10;
    no_coins ++;
  }
  
  // No of 5s
  while(m >= 5)
  {
    m = m - 5;
    no_coins ++;
  }
  
  // No of 1s
  while(m >= 1)
  {
    m = m - 1;
    no_coins ++;
  }
  
  return no_coins;
}

int main()
{
  int m;
  scanf("%d", &m);
  
  int change = get_change(m);
  
  printf("%d\n", change);
  return 0;
}
