#include <stdio.h>

struct Item
{
  int weight;
  int value;
  double ratio;
};

int partition(struct Item array[], int left, int right)
{
  int pivot = array[left].ratio;
  
  while(left < right)
  {
    while(array[left].ratio > pivot)
      left ++;
    
    while(array[right].ratio < pivot)
      right --;
      
    if(left >= right)
      return right;
    
    // swap 
    struct Item temp = array[left];
    array[left] = array[right];
    array[right] = temp;
  }
}

void quick_sort(struct Item array[], int left, int right)
{
  if(left < right)
  {
    int separator = partition(array, left, right);
    quick_sort(array, left, separator);
    quick_sort(array, separator + 1, right);
  }
}

double get_optimal_value(int capacity, int no_items, struct Item items[]) 
{
  double value = 0.0;
  int index = 0, empty = capacity;
  
  quick_sort(items, 0, no_items - 1);
  
  index = 0;
  while(empty > 0 && index < no_items)
  {
    if(items[index].weight <= empty)
    {
      empty -= items[index].weight;
      value += items[index].value;
      index ++;
    }
    else
    {
      value += items[index].ratio * empty;
      empty = 0;
    }
  }
  
  return value;
}

int main()
{
  int no_items, capacity, index;
  struct Item items[100];
  
  scanf("%d %d", &no_items, &capacity);
  
  for(index = 0; index < no_items; index ++)
  {
    scanf("%d %d", &items[index].value, &items[index].weight);
    items[index].ratio = (double) items[index].value / items[index].weight;
  }
  
  double value = get_optimal_value(capacity, no_items, items);
  
  printf("%lf\n", value);
   
  return 0;
}
