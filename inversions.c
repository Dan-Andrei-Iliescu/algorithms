#include <stdio.h>

int merge(int array[], int left, int ave, int right)
{
  int ind_a = left, ind_b = ave + 1, ind_x = 0, index;
  long long inv = 0;
  int aux[100001];
  
  while(ind_a <= ave && ind_b <= right)
  {
    if(array[ind_a] <= array[ind_b])
      aux[++ ind_x] = array[ind_a ++];
    else 
    {
      aux[++ ind_x] = array[ind_b ++];
      inv += ave - ind_a + 1;
    }
  }
  
  if(ind_b > right)
    for(ind_a; ind_a <= ave; ind_a ++)
    {
      aux[++ ind_x] = array[ind_a];
    }
  
  for(index = 1; index <= ind_x; index ++)
    array[left + index - 1] = aux[index];
  
  //printf("Pentru %d, %d, %d sunt %llu inversiuni\n", left, ave, right, inv);
    
  return inv;
}

long long get_number_of_inversions(int array[], int left, int right) 
{
  long long inv = 0;
  
  //printf("Calculam pentru %d si %d\n", left, right);
  
  if (right <= left) 
    return inv;
  
  if(left + 1 == right)
    if(array[right] < array[left])
    {
      int temp = array[left];
      array[left] = array[right];
      array[right] = temp;
      return 1;
    }
    else return 0;
    
  int ave = (right + left) / 2;
  
  inv += get_number_of_inversions(array, left, ave);
  inv += get_number_of_inversions(array, ave + 1, right);
  
  //write your code here
  
  inv += merge(array, left, ave, right);
  
  //printf("Pentru %d, %d sunt %llu inversiuni\n", left, right, inv);
   
  return inv;
}

int main()
{
  int size, array[100001], index;
  
  scanf("%d", &size);
  
  for(index = 0; index < size; index ++)
    scanf("%d", &array[index]);
    
  long long inv = get_number_of_inversions(array, 0, size - 1);
  
 // for(index = 0; index < size; index ++)
    //printf("%d ", array[index]);
  
  printf("%llu\n", inv);
    
  return 0; 
}
