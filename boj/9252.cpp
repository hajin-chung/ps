#include <bits/stdc++.h>
using namespace std;

char a[1005], b[1005];
int dp[1005][1005];

int main() {
  scanf("%s %s", &a[1], &b[1]);
  int n = max(strlen(&a[1]), strlen(&b[1])), mx = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1]+1;
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      mx = max(mx, dp[i][j]);
    }
  printf("%d\n", mx);
}
