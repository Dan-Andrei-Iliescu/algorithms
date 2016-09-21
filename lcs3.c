#include <stdio.h>

int min_2(int a, int b)
{
  return (a < b) ? a : b;
}

int max_2(int a, int b)
{
  return (a > b) ? a : b;
}

int min_3(int a, int b, int c)
{
  int d = min_2(a, b);
  return (d < c) ? d : c;
}

int max_3(int a, int b, int c)
{
  int d = max_2(a, b);
  return (d > c) ? d : c;
}

int max_6(int a, int b, int c, int d, int e, int f)
{
  int g = max_3(a, b, c);
  int h = max_3(d, e, f);
  return (g > h) ? g : h;
}

int lcs_3[102][102][102];

int main()
{
  int a[102], b[102], c[102], a_len, b_len, c_len; 
  int i, j, k, lcs_2[102][102];
  int insertion, deletion, match, mismatch, sol[102][102];
  
  scanf("%d", &a_len);
  
  for(i = 1; i <= a_len; i ++)
    scanf("%d", &a[i]);
    
  scanf("%d", &b_len);
  
  for(j = 1; j <= b_len; j ++)
    scanf("%d", &b[j]);
    
  scanf("%d", &c_len);
  
  for(j = 1; j <= c_len; j ++)
    scanf("%d", &c[j]);
    
  for(i = 1; i <= a_len; i ++)
    for(j = 1; j <= b_len; j ++)
      for(k = 1; k <= c_len; k ++)
        if(a[i] == b[j] && b[j] == c[k])
          lcs_3[i][j][k] = lcs_3[i - 1][j - 1][k - 1] + 1;
        else 
          lcs_3[i][j][k] 
            = max_6(lcs_3[i - 1][j][k], lcs_3[i][j - 1][k], lcs_3[i][j][k - 1],
                    lcs_3[i - 1][j - 1][k], lcs_3[i - 1][j][k - 1], lcs_3[i][j - 1][k - 1]);
  
  printf("%d\n", lcs_3[a_len][b_len][c_len]);
    
  /*
  for(i = 0; i <= a_len; i ++) lcs_2[i][0] = 0;
  for(j = 0; j <= b_len; j ++) lcs_2[0][j] = 0;
  
  for(i = 1; i <= a_len; i ++)
    for(j = 1; j <= b_len; j ++)
      if(a[i] == b[j])
        lcs_2[i][j] = lcs_2[i - 1][j - 1] + 1;
      else lcs_2[i][j] = max_2(lcs_2[i - 1][j], lcs_2[i][j - 1]);
  
  printf("%d\n", lcs_2[a_len][b_len]);
  */
  /*
  for(i = 0; i <= a_len; i ++) sol[i][0] = i;
  for(j = 0; j <= b_len; j ++) sol[0][j] = j;
  
       printf("\n");
  
  for(i = 1; i <= a_len; i ++)
  {
    for(j = 1; j <= b_len; j ++)
    {
      insertion = sol[i][j - 1] + 1;
      deletion = sol[i - 1][j] + 1;
      match = sol[i - 1][j - 1];
      // mismatch = sol[i  - 1][j - 1] + 1;
      
      if(a[i] == b[j])
        sol[i][j] = min_3(insertion, deletion, match);
      else // sol[i][j] = min_3(insertion, deletion, mismatch);
           sol[i][j] = min_2(insertion, deletion);
      
       printf("%d ", sol[i][j]); 
    }
     printf("\n");
  }
  
  int result = (a_len + b_len - sol[a_len][b_len]) / 2;
  
  printf("Edit distance is %d and result is %d", sol[a_len][b_len], result);
  */
  
  
  return 0;
}
