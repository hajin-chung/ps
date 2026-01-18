#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int n, a[1005][4], dp[1005][4];

int solve(int fc, int lc) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 3; j++)
      dp[i][j] = INF;
  for (int i = 0; i < 3; i++)
    if (i != fc)
      dp[1][i] = a[0][fc] + a[1][i];
  for (int i = 2; i < n-1; i++) {
    dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + a[i][0];
    dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + a[i][1];
    dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + a[i][2];
  }
  int ret = INF;
  for (int i = 0; i < 3; i++)
    if (i != lc)
      ret = min(ret, dp[n-2][i]);
  return a[n-1][lc] + ret; 
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
  int ans = INF;
  for (int fc = 0; fc < 3; fc++)
    for (int lc = 0; lc < 3; lc++)
      if (fc != lc)
        ans = min(ans, solve(fc, lc));
  cout << ans << "\n";
}
