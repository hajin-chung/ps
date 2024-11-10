#include <bits/stdc++.h>
using namespace std;

int dp[105][105][105];
char a[3][105];

int max3(int x, int y, int z) { return max(x, max(y, z)); }

int main() {
  for (int i = 0; i < 3; i++) scanf("%s", &a[i][1]);
  int n = strlen(&a[0][1]), m = strlen(&a[1][1]), o = strlen(&a[2][1]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int k = 1; k <= o; k++) {
        if (a[0][i] == a[1][j] && a[1][j] == a[2][k])
          dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
        else
          dp[i][j][k] = max3(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]);
      }
  printf("%d\n", dp[n][m][o]);
}
