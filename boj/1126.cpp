#include <bits/stdc++.h>
#define MAX 500000
using namespace std;

int n, dp[55][MAX+5];
vector<int> a;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n; a.resize(n+1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(dp, -1, sizeof(dp));

  dp[0][0] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= MAX; j++)
      if (dp[i-1][j] != -1) {
        dp[i][j] = max(dp[i][j], dp[i-1][j]);
        dp[i][j+a[i]] = max(dp[i][j+a[i]], dp[i-1][j]+a[i]);
        if (j > a[i]) dp[i][j-a[i]] = max(dp[i][j-a[i]], dp[i-1][j]);
        else dp[i][a[i]-j] = max(dp[i][a[i]-j], dp[i-1][j] + a[i]-j);
      }

  if (dp[n][0] != 0) cout << dp[n][0] << "\n";
  else cout << "-1\n";
}
