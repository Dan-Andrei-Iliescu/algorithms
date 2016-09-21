#include <stdio.h>


int main()
{
  int index, size, left[101], right[101], pins[101];
  
  scanf("%d", &size);
  
  for (index = 1; index <= size; index ++)
    scanf("%d %d", &left[index], &right[index]);
  
  int min, pin, no_pins = 0;
  
  while(size >= 1)
  {
    min = 1;
    
    for(index = 1; index <= size; index ++)
    {
      if(right[index] < right[min])
        min = index;
    }   
    
    pin = right[min];
    
    //printf("%d\n", pin);
    
    for(index = 1; index <= size; index ++)
      if(left[index] <= pin)
      {
        //printf("%d ", left[index]);
        
        left[index] = left[size];
        right[index] = right[size];
        index --;
        size --;
      }
      
    pins[++ no_pins] = pin;
  }
  
  printf("%d\n", no_pins);
  
  for(index = 1; index <= no_pins; index ++)
    printf("%d\n", pins[index]);
  
  return 0;
}
