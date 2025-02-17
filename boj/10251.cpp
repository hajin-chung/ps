#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 100;
const int M = 100;
int a[N][M][2];
int dp[N][M][N+M+5][2];

void mn(int &x, int v) { if (x > v) x = v; }

void f() {
  int n, m, g, l; cin>>n>>m>>l>>g;
  int mxd = 200;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m-1; j++)
      cin>>a[i][j][0];
  for (int i = 0; i < n-1; i++)
    for (int j = 0; j < m; j++)
      cin>>a[i][j][1];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      for (int d = 0; d <= mxd; d++)
        dp[i][j][d][0] = dp[i][j][d][1] = INF;
  dp[0][0][0][0] = dp[0][0][0][1] = 0;
  for (int i = 1; i < n; i++) dp[i][0][0][1] = dp[i-1][0][0][1] + a[i-1][0][1];
  for (int i = 1; i < m; i++) dp[0][i][0][0] = dp[0][i-1][0][0] + a[0][i-1][0];
  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++)
      for (int d = 1; d <= 2*min(i, j); d++) {
        dp[i][j][d][0] = min(dp[i][j-1][d][0], dp[i][j-1][d-1][1])+a[i][j-1][0];
        dp[i][j][d][1] = min(dp[i-1][j][d][1], dp[i-1][j][d-1][0])+a[i-1][j][1];
      }
  int ans = -1;
  for (int d = 0; d <= mxd; d++)
    if (dp[n-1][m-1][d][1] <= g || dp[n-1][m-1][d][0] <= g) {
      ans = d;
      break;
    }
  if (ans != -1) {
    cout<<(n+m-2)*l+ans<<"\n";
  } else cout<<ans<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) f();
}
