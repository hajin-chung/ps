#include <bits/stdc++.h>
using namespace std;

bool a[1005][1005];
int dp[1005][1005];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, t; cin>>n>>m>>t;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin>>a[i][j];
  dp[0][0] = t-1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      dp[i+1][j] = dp[i][j]/2 + (dp[i][j] % 2 && !a[i][j]);
      dp[i][j+1] = dp[i][j]/2 + (dp[i][j] % 2 && a[i][j]);
    }
  int yy = 0, xx = 0;
  while (yy < n && xx < m) {
    if (dp[yy][xx]%2) {
      if (a[yy][xx]) yy++;
      else xx++;
    } else {
      if (a[yy][xx]) xx++;
      else yy++;
    }
  }
  cout<<yy+1<<" "<<xx+1<<"\n";
}
