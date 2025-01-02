#include <bits/stdc++.h>
using namespace std;

int dp[2005][2005];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin>>n>>m;
  vector<int> a(n+1), b(m+1);
  for (int i = 0; i < n; i++) {
    char c; cin>>c;
    a[n-i] = c == 'I';
  }
  for (int i = 0; i < m; i++) {
    char c; cin>>c;
    b[m-i] = c == 'I';
  }
  dp[1][0] = a[1]; dp[0][1] = b[1];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (i == 1 && j == 1) continue;
      int mx = a[i] || b[j];
      if (i > 1 && a[i] && !a[i-1] && dp[i-2][j]) mx = max(mx, dp[i-2][j]+2);
      if (j > 1 && b[j] && !b[j-1] && dp[i][j-2]) mx = max(mx, dp[i][j-2]+2);
      if (((a[i] && !b[j]) || (!a[i] && b[j])) && dp[i-1][j-1]) 
        mx = max(mx, dp[i-1][j-1]+2);
      dp[i][j] = mx;
    }
  int ans = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++)
      ans = max(ans, dp[i][j]);
  cout<<ans<<"\n";
}
