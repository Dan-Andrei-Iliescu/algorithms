#include <stdio.h>

int order[500001];

void prt(int array[], int size)
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
    
    temp = order[a + index];
    order[a + index] = order[b + index];
    order[b + index] = temp;
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

void count_segments(int left[], int right[], int segs, int point[], int points, int count[])
{ 
  int index;
  
  quick_3(left, 0, segs - 1);
  
  quick_3(right, 0, segs - 1); 
  
  for(index = 0; index < points; index ++)
    order[index] = index;
  
  quick_3(point, 0, points - 1);
  
  // ------------------------------------
  //prt(left, segs);
  //prt(order, points);
  //prt(point, points);
  //prt(order_prime, points);
  // ------------------------------------
  
  //for(index = 0; index < points; index ++)
  //  printf("%d ", point[order_prime[index]]);
  //printf("\n");
  
  int open = 0, ind_l = 0, ind_r = 0, ind_p = 0;
  
  left[segs] = right[segs] = point[points] = 100000000;
  
  while(ind_l < segs || ind_r < segs || ind_p < points)
  {
    if(left[ind_l] <= right[ind_r] && left[ind_l] <= point[ind_p])
    {
      open ++;
      ind_l ++;
      
      //printf("Deschidere \n");
    }  
    else if(point[ind_p] <= right[ind_r] && left[ind_l] >= point[ind_p])
    {
      count[order[ind_p]] = open;
      ind_p ++;
      
      ///printf("Punct \n");
    }  
    else if(left[ind_l] >= right[ind_r] && right[ind_r] <= point[ind_p])
    {
      open --;
      ind_r ++;
      
      //printf("Inchidere \n");
    }
    
   /// printf("%d\n", open);
  }
}

int main()
{
  int left[50001], right[50001], point[50001], count[50001];
  int segs, points, index;
  
  scanf("%d %d", &segs, &points);
    
  for(index = 0; index < segs; index ++)
    scanf("%d %d", &left[index], &right[index]);
    
  for(index = 0; index < points; index ++)
    scanf("%d", &point[index]);
    
  count_segments(left, right, segs, point, points, count);
  
  for(index = 0; index < points; index ++)
    printf("%d ", count[index]);
    
  return 0;
}
