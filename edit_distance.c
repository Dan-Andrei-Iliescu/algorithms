#include <stdio.h>
#include <string.h>

int min_3(int a, int b, int c)
{
  if(a < b)
    if(a < c) return a;
    else return c;
  else if(b < c) return b;
  else return c;
}

int main()
{
  char a[102], b[102]; 
  int i, j, insertion, deletion, match, mismatch, sol[102][102];
  
  fgets(a, sizeof(a), stdin);
  fgets(b, sizeof(b), stdin);
  
  int n = strlen(a);
  int m = strlen(b);
  
  for(i = 0; i <= n; i ++) sol[i][0] = i;
  for(j = 0; j <= m; j ++) sol[0][j] = j;
  
  for(i = 1; i <= n; i ++)
  {
    for(j = 1; j <= m; j ++)
    {
      insertion = sol[i][j - 1] + 1;
      deletion = sol[i - 1][j] + 1;
      match = sol[i - 1][j - 1];
      mismatch = sol[i - 1][j - 1] + 1;
      
      if(a[i - 1] == b[j - 1])
        sol[i][j] = min_3(insertion, deletion, match);
      else sol[i][j] = min_3(insertion, deletion, mismatch);
      
      // printf("%d ", sol[i][j]); 
    }
    // printf("\n");
  }
  printf("%d", sol[n][m]);
  
  return 0;
}

// (i, j) = min((i, j-1) + 1, (i-1, j) + 1, (i-1, j-1) + 1, (i-1, j-1))
