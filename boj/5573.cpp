#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, t; cin>>n>>m>>t;
  bool a[1005][1005];
  int dp[1005][1005];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin>>a[i][j];
  dp[0][0] = t-1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      dp[i+1][j] += dp[i][j]/2 + (dp[i][j] % 2 && !a[i][j]);
      dp[i][j+1] += dp[i][j]/2 + (dp[i][j] % 2 && a[i][j]);
    }
  int yy = 0, xx = 0;
  while (yy < n && xx < m) {
    if (dp[yy][xx]%2 == a[yy][xx]) yy++;
    else xx++;
  }
  cout<<yy+1<<" "<<xx+1<<"\n";
}
