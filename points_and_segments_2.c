#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int order[50001];
int cnt[50001];
int start[50001], end[50001], point[50001], seg[50001];

int cmp(const void *a, const void *b)
{
  return (*(int *) a - *(int*) b);
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

void naive_count_segments(int starts[], int ends[], int points[], int p, int s) {
  int i, j;
  for (i = 0; i < p; i++) {
    for (j = 0; j < s; j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
}

int main()
{
  int i, s, p;
  
  // Correct reading 
  scanf("%d %d", &s, &p);
  
  for(i = 0; i < p ; i ++)
    order[i] = i;
    
  for(i = 0; i < s; i++)
    scanf("%d %d", &start[i], &end[i]);
    
  for(i = 0; i < p; i ++)
  {
    scanf("%d", &point[i]);
    // printf("%d\n", point[i]);
  }
  
  qsort(start, s, sizeof(int), cmp);
  qsort(end, s, sizeof(int), cmp);
  quick_3(point, 0, p - 1);
  
  /*
  // ===========================================================================
  for(i = 0; i < s; i++)
    printf("%d ", start[i]);
  printf("\n");
  
  for(i = 0; i < s; i++)
    printf("%d ", end[i]);
  printf("\n");
  
  for(i = 0; i < p; i++)
    printf("%d ", point[i]);
  printf("\n");
  // ===========================================================================
  */
  
  int j = 0, k = 0, open = 0;
  i = 0;
  
  while(i < s && j < s && k < p)
  {
    if(start[i] <= end[j] && start[i] <= point[k])
    {
      //  printf("Start %d %d \n", start[i], open);
      open ++;
      i ++;
    }
    else if(point[k] <= start[i] && point[k] <= end[j])
    {
      // printf("Point %d %d \n", point[k], open);
      seg[order[k]] = open;
      k ++;
    }
    else if(end[j] <= start[i] && end[j] <= point[k])
    {
      // printf("End %d %d \n", end[j], open);
      open --;
      j ++;
    }
  }
  
  while(j < s && k < p)
  {
    if(point[k] <= end[j])
    {
      // printf("Point %d %d \n", point[k], open);
      seg[order[k]] = open;
      k ++;
    }
    else if(end[j] <= point[k])
    {
      // printf("End %d %d \n", end[j], open);
      open --;
      j ++;
    }
  }
  
  for(k = 0; k < p; k++)
    printf("%d ", seg[k]);
  printf("\n");   
  return 0;
}
