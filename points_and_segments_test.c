#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int order[50001];
int cnt[50001];

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
      // printf("Point %d inside segment %d and %d \n", points[i], starts[j], ends[j]);
    }
  }
}

int main()
{
  int i, start[50001], end[50001], point[50001], seg[50001], s, p;
  
  // Correct reading
  /*  
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
  */
  // ===========================================================================
  
    
  int ok = 1;
  int test = 0;
  
  int t = 1;
  
  while(ok == 1)
  {
  
  test ++;
  printf("\n\n=================================================================\n");
  printf("TEST %d \n", test);
  printf("=================================================================\n");
  
  int SIZE = 50000;
  int SIZE_2 = 100000000;
  
  s = rand() % SIZE + 1;
  p = rand() % SIZE + 1;
  
  printf("SIZES ARE: \n");
  printf("%d %d\n", s, p);
  printf("-----------------------------------------------------------------\n");
  
  for(i = 0; i < p ; i ++)
    order[i] = i;
  
  printf("POINTS ARE: \n");
  for(i = 0; i < p; i ++)
  {
    point[i] = pow(-1, rand() % 2) * (rand() % SIZE_2);
    printf("%d ", point[i]);
  }
  printf("\n-----------------------------------------------------------------\n");
   
  printf("SEGMENTS ARE: \n");
  for(i = 0; i < s; i++)
  {
    start[i] = pow(-1, rand() % 2) * (rand() % SIZE_2);
    end[i] = start[i] + (rand() % SIZE_2);
    printf("%d %d \n", start[i], end[i]);
  }
  printf("-----------------------------------------------------------------\n");
  
  // ===========================================================================
  naive_count_segments(start, end, point, p, s);
  
  qsort(start, s, sizeof(int), cmp);
  qsort(end, s, sizeof(int), cmp);
  quick_3(point, 0, p - 1);
  
  // ===========================================================================
  
  // ===========================================================================
  
  int j = 0, k = 0, open = 0;
  i = 0;
  
  while(i < s && j < s && k < p)
  {
    if(start[i] <= end[j] && start[i] <= point[k])
    {
      // printf("Start %d %d \n", start[i], open);
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
  
  // ===========================================================================
  for(k = 0; k < p; k++)
    if(seg[k] == cnt[k])
    {
      printf("Rezultat: %d %d   ", seg[k], cnt[k]);
      printf("OK\n");
    }
    else
    {
      printf("Rezultat: %d %d   ", seg[k], cnt[k]);
      printf("EROARE la %d \n", k);
      ok = 0;
    }
  
  for(i = 0; i <= 50001; i++)
  {
    cnt[i] = 0;
    seg[i] = 0;
  }
   
  printf("TEST %d", test);
  // ===========================================================================  
  
  }
    
  return 0;
}
