#include <stdio.h>

int main()
{
  int n, W, weight[100001], value[10001][2], i, w, val;
  
  scanf("%d %d", &W, &n);
  
  for(i = 1; i <= n; i ++)
   scanf("%d", &weight[i]);
  
  value[0][1] = 0;
  for(w = 1; w <= W; w ++) value[w][0] = 0;
  
  int aux_i = 0;
  
  for(i = 1; i <= n; i ++)
  {
    aux_i = 1 - aux_i;
    for(w = 1; w <= W; w ++)
    {
      value[w][aux_i] = value[w][1 - aux_i];
      if(weight[i] <= w)
      {
        val = value[w - weight[i]][1 - aux_i] + weight[i];
        if(value[w][aux_i] < val)
          value[w][aux_i] = val;
      }
    }
  }
  
  printf("%d", value[W][aux_i]);
   
  return 0;
}
