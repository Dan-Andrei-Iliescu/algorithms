#include <stdio.h>

int main()
{
  int n, summands[100001], no_summands = 0;
  
  scanf("%d", &n);
  
  int k = n, l = 1, index;
  
  while(k > 2 * l)
  {
    summands[++ no_summands] = l;
    k -= l;
    l ++;
  }
  
  summands[++ no_summands] = k;
  
  printf("%d\n", no_summands);
  
  for(index = 1; index <= no_summands; index ++)
    printf("%d ", summands[index]);
    
  return 0;
}
