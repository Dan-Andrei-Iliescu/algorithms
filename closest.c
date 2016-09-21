#include <stdio.h>
#include <math.h>

int order[100001], x[100001], y[100001];

void swap(int array[], int a, int b, int length)
{
  int index, temp;
  for(index = 0; index < length; index ++)
  {
    temp = array[a + index];
    array[a + index] = array[b + index];
    array[b + index] = temp;
    
    temp = order[a + index];
    order[a+index] = order[b+index];
    order[b+index] = temp;
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

double shortest_distance(int left, int right)
{
  int midway = (left + right) / 2;
  double dist;
  
  if(left == right)
    return 100000000;
  
  double left_dist = shortest_distance(left, midway);
  double right_dist = shortest_distance(midway + 1, right);
  
  double min_dist = (left_dist < right_dist) ? left_dist : right_dist;
  //printf("%f\n", min_dist);
  int i = midway, j;
  while(x[midway] - x[i] < min_dist && i >= left && i >= midway - 100)
  {
    j = midway + 1;
    while(x[j] - x[i] < min_dist && j <= right && j <= midway + 100)
    {
      dist = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
      // printf("Distanta intre %d %d si %d %d este %f\n", x[i], y[i], x[j], y[j], dist);
      if(dist < min_dist)
      {
        //printf("Distanta intre %d %d si %d %d este %f\n", x[i], y[i], x[j], y[j], dist);
        min_dist = dist;
      }
      j ++;
    }
    i --;
  }
    
  return min_dist;
}

int main()
{
  int n, i, temp[100001];
  
  scanf("%d", &n);
  
  for(i = 0; i < n; i ++)
    scanf("%d %d", &x[i], &y[i]);
  
  for(i = 0; i < n; i ++)
    order[i] = i;
    
  quick_3(x, 0, n - 1);
  
  for(i = 0; i < n; i ++)
    temp[i] = y[order[i]];
    
  for(i = 0; i < n; i ++)
    y[i] = temp[i];
  
  //for(i = 0; i < n; i ++)
    //printf("%d %d \n", i, order[i]);
    //printf("X %d, Y %d, Order %d \n", x[i], y[i], order[i]);
   
  double result = shortest_distance(0, n - 1);
  
  printf("%f\n", result);
  
  return 0;
}
