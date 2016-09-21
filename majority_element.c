#include <stdio.h>

int get_majority_element(int array[], int left, int right)
{
  int candidate = 0, index;
  
  if (left > right) return -1;
  if (left == right) return array[left];
  //write your code here
  
  int midway = (left + right) / 2;
  
  int l_maj = get_majority_element(array, left, midway);
  int r_maj = get_majority_element(array, midway + 1, right);
  
  if(l_maj == -1 && r_maj == -1)
    return -1;
  else if(l_maj == -1)
  {
    for(index = left; index <= right; index ++)
      if(array[index] == r_maj)
        candidate ++;
    
    if(candidate > (right - left + 1) / 2)
      return r_maj;
    else return -1;
  }
  else if(r_maj == -1)
  {
    for(index = left; index <= right; index ++)
      if(array[index] == l_maj)
        candidate ++;
    
    if(candidate > (right - left + 1) / 2)
      return l_maj;
    else return -1;
  }
  else
  {
    for(index = left; index <= right; index ++)
      if(array[index] == r_maj)
        candidate ++;
    
    if(candidate > (right - left + 1) / 2)
      return r_maj;
    
    candidate = 0;
    
    for(index = left; index <= right; index ++)
      if(array[index] == l_maj)
        candidate ++;
    
    if(candidate > (right - left + 1) / 2)
      return l_maj;
    else return -1;
  }
  
  for(index = left; index <= right; index++)
    
  return -1;
}

int main()
{
  int index, size, array[100001];
  
  scanf("%d", &size);
  
  for(index = 1; index <= size; index ++)
    scanf("%d", &array[index]);
  
  int maj = get_majority_element(array, 1, size);
  int result = (maj != -1);
  
  printf("%d\n", result);
  
  return 0;
}
