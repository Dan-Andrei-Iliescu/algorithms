#include <stdio.h>

long long min_dot_product(long a[], long b[], int size)
{
  long long result = 0;
  int max, min, index;
  
  for(size; size >= 1; size --)
  {
    max = min = 1;
    
    for(index = 1; index <= size; index ++)
    {
      if(a[index] < a[min])
        min = index;
    
      if(b[index] > b[max])
        max = index;
    }   
  
    result += a[min] * b[max];
    
    a[min] = a[size];
    b[max] = b[size];
  }
  
  return result;
}

int main()
{
  int size, index;
  long a[1001], b[1001];
  
  scanf("%d", &size);
  
  for(index = 1; index <= size; index ++)
    scanf("%ld", &a[index]);
    
  for(index = 1; index <= size; index ++)
    scanf("%ld", &b[index]);
    
  long long result = min_dot_product(a, b, size);
  
  printf("%lld\n", result);
}
