#include <stdio.h>
#include <string.h>
#define INF 1000000000

int dp[10005][3], a[10005][2], n, w;
int min2(int a, int b) { return a > b ? b : a; }
int min(int a, int b, int c) { return min2(a, min2(b, c)); }
int tps(int a, int b) { return a + b <= w ? 1 : 2; }

void fill() {
  for (int i = 2; i <= n; i++) {
    dp[i][0] = min(dp[i-1][0], dp[i-1][1]+1, dp[i-1][2]+1) + tps(a[i][0], a[i][1]);
    dp[i][0] = min2(dp[i][0], dp[i-2][0] + tps(a[i-1][0], a[i][0]) + tps(a[i-1][1], a[i][1]));
    dp[i][1] = min(dp[i-1][2] + tps(a[i-1][0], a[i][0]), dp[i-1][0] + 1, dp[i-1][1] + 2);
    dp[i][2] = min(dp[i-1][1] + tps(a[i-1][1], a[i][1]), dp[i-1][0] + 1, dp[i-1][2] + 2);
  }
}

void print() {
  // printf("\n");
  // for (int i = 0; i < 3; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     if (dp[j][i] == INF) printf(". ");
  //     else printf("%d ", dp[j][i]);
  //   }
  //   printf("\n");
  // }
  // printf("\n");
}

void solve() {
  int ans = INF;
  scanf("%d%d", &n, &w);
  for (int i = 0; i < 2; i++)
    for (int j = 1; j <= n; j++)
      scanf("%d", &a[j][i]);

  memset(dp, 0, 10005*3*sizeof(int));
  dp[1][0] = tps(a[1][0], a[1][1]);
  dp[1][1] = INF;
  dp[1][2] = INF;
  fill();
  ans = min2(ans, min(dp[n][0], dp[n][1]+1, dp[n][2]+1));
  print();

  memset(dp, 0, 10005*3*sizeof(int));
  dp[0][0] = dp[0][1] = dp[0][2] = INF;
  dp[1][0] = tps(a[1][0], a[n][0]) + tps(a[1][1], a[n][1]);
  dp[1][1] = INF;
  dp[1][2] = INF;
  fill();
  ans = min2(ans, min(dp[n-1][0], dp[n-1][1]+1, dp[n-1][2]+1));
  print();

  memset(dp, 0, 10005*3*sizeof(int));
  dp[0][0] = dp[0][1] = dp[0][2] = INF;
  dp[1][0] = INF;
  dp[1][1] = tps(a[1][0], a[n][0]);
  dp[1][2] = INF;
  fill();
  ans = min2(ans, min2(dp[n-1][0]+1, dp[n][2]));
  print();

  memset(dp, 0, 10005*3*sizeof(int));
  dp[0][0] = dp[0][1] = dp[0][2] = INF;
  dp[1][0] = INF;
  dp[1][1] = INF;
  dp[1][2] = tps(a[1][1], a[n][1]);
  fill();
  ans = min2(ans, min2(dp[n-1][0]+1, dp[n][1]));
  print();

  printf("ans:: %d\n", ans);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
