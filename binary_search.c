#include <stdio.h>

int binary_search(int array[], int left, int right, int item)
{
  int midway = (left + right) / 2;
  
  if(left > right)
    return -1;
  else if(array[midway] == item)
    return midway;
  else if(array[midway] > item)
    return binary_search(array, left, midway - 1, item);
  else if(array[midway] < item)
    return binary_search(array, midway + 1, right, item);
}

int main()
{
  int size, result, index, number, array[100001], item;
  
  scanf("%d", &size);
  
  for(index = 0; index < size; index ++)
    scanf("%d", &array[index]);
    
  scanf("%d", &number);
  
  for(index = 0; index < number; index ++)
  {
    scanf("%d", &item);
    
    result = binary_search(array, 0, size - 1, item);
    
    printf("%d ", result);
  }
  
  return 0;
}
