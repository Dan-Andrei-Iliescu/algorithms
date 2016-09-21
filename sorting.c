#include <stdio.h>

int size;

void prt(int array[])
{
  int index;
  for(index = 0; index < size; index ++)
    printf("%d ", array[index]);
  
  printf("\n");  
}

void swap(int array[], int a, int b, int length)
{
  int index, temp;
  for(index = 0; index < length; index ++)
  {
    temp = array[a + index];
    array[a + index] = array[b + index];
    array[b + index] = temp;
  }
}

void partition_3(int array[], int left, int right, int sep[])
{
  int pivot = array[left], index;
  sep[0] = sep[1] = left;
  
  for(index = left + 1; index <= right; index ++)
  {
    if(array[index] == pivot)
    {
      sep[1]++;
      swap(array, sep[1], index, 1);
    }
    else if(array[index] < pivot)
    {
      sep[1] ++;
      swap(array, sep[1], index, 1);
      swap(array, sep[0], sep[1], 1);
      sep[0] ++;
    }
  }
}

void quick_3(int array[], int left, int right)
{
  int sep[2];
  
  if(left >= right)
    return;
  
  int k = left + 3785109 % (right - left + 1);
  
  swap(array, left, k, 1);
  
  partition_3(array, left, right, sep);
    
  quick_3(array, left, sep[0] - 1);
  quick_3(array, sep[1] + 1, right);
}

int main() 
{
  int index, array[100001];
  
  scanf("%d", &size);
  
  for(index = 0; index < size; index ++)
    scanf("%d", &array[index]);
    
  quick_3(array, 0, size - 1);
  
  prt(array);
  
  return 0;
}
