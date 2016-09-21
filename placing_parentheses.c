#include <stdio.h>
#include <string.h>

char op[30], string[30];
long long m[30][30], M[30][30];
int no[30];

long long min_2(long long a, long long b)
{
  return (a < b) ? a : b;
}

long long max_2(long long a, long long b)
{
  return (a > b) ? a : b;
}

long long min_4(long long a, long long b, long long c, long long d)
{
  long long e = min_2(a, b);
  long long f = min_2(c, d);
  return (e < f) ? e : f;
}

long long max_4(long long a, long long b, long long c, long long d)
{
  long long e = max_2(a, b);
  long long f = max_2(c, d);
  return (e > f) ? e : f;
}

long long min_5(long long a, long long b, long long c, long long d, long long e)
{
  long long f = min_4(a, b, c, d);
  return (e < f) ? e : f;
}

long long max_5(long long a, long long b, long long c, long long d, long long e)
{
  long long f = max_4(a, b, c, d);
  return (e > f) ? e : f;
}

long long eval(long long a, long long b, char op) {
  if (op == '*')
    return a * b;
  else if (op == '+')
    return a + b;
  else if (op == '-')
    return a - b;
  else
    return 0;
}

long long parantheses(int n)
{
  long long min = 9223372036854775807, max = -9223372036854775807;
  long long a, b, c, d;
  int i, j, s, k;
  
  for(i = 1; i <= n + 1; i ++)
  {
    m[i][i] = no[i];
    M[i][i] = no[i];
  }
  
  for(s = 1; s <= n; s ++)
    for(i = 1; i <= n + 1 - s; i ++)
    {
      j = i + s;
      
      min = 9223372036854775807; 
      max = -9223372036854775807;
      
      for(k = i; k <= j - 1; k ++)
      {
        a = eval(m[i][k], m[k + 1][j], op[k]);
        b = eval(m[i][k], M[k + 1][j], op[k]);
        c = eval(M[i][k], m[k + 1][j], op[k]);
        d = eval(M[i][k], M[k + 1][j], op[k]);
        
        min = min_5(min, a, b, c, d);
        max = max_5(max, a, b, c, d);
      }
      
      m[i][j] = min;
      M[i][j] = max;
    }
  
  return M[1][n + 1];
}

int main()
{
  int i, j;
  
  fgets(string, sizeof(string), stdin);
  
  int len = strlen(string);
  int n = (len - 1) / 2;
  
  for(i = 0; i <= len; i ++)
    if(i % 2 == 0)
      no[i / 2 + 1] = string[i] - '0';
    else
      op[i / 2 + 1] = string[i];
  
  /*for(i = 1; i <= n + 1; i ++)
    printf("%d ", no[i]);
  
  printf("\n");
  
  for(i = 1; i <= n; i ++)
    printf("%c ", op[i]);
  
  printf("\n");*/
   
  long long result = parantheses(n);
  
  /*for(i = 1; i <= n + 1; i ++)
  {
    for(j = 1; j <= n + 1; j ++)
      printf("%lld ", m[i][j]);
    printf("\n");
  } 
  
  printf("\n");
  
  for(i = 1; i <= n + 1; i ++)
  {
    for(j = 1; j <= n + 1; j ++)
      printf("%lld ", M[i][j]);
    printf("\n");
  }*/
    
  printf("%lld\n", result);
  
  return 0;
}
