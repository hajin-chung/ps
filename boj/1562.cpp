#include <stdio.h>
#define MOD 1000000000
#define N (1<<10)

int n;
int d[N][10], sum, tmp[N][10];

int solve(int n) {
  int i, j, k;

  for (j = 0; j < N; j++)
    for (k = 0; k < 10; k++) 
      d[j][k] = tmp[j][k] = 0;
  
  for(i = 1; i <= 9; i++) d[1<<i][i] = 1;

  for(i = 1; i <= n - 1 ; i++) {
    for (j = 0; j < N; j++)
      for(k = 0; k <= 9; k++)
        if (d[j][k]) {
          if (k > 0) tmp[j | (1 << (k-1))][k-1] = (tmp[j | (1 << (k-1))][k-1] + d[j][k]) % MOD;
          if (k < 9) tmp[j | (1 << (k+1))][k+1] = (tmp[j | (1 << (k+1))][k+1] + d[j][k]) % MOD;
        }

    for (j = 0; j < N; j++)
      for (k = 0; k < 10; k++) {
        d[j][k] = tmp[j][k];
        tmp[j][k] = 0;
      }
  }

  sum = 0;
  for(i = 0; i <= 9; i++)
    sum += d[N - 1][i], sum%=MOD;
  return sum;
}

int main() {
  scanf("%d", &n);
  int ans = solve(n);
  printf("%d\n", ans);
  return 0;
}
