#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

typedef uint64_t ll;
const int N = 2000;
const int MOD = 1e9+7;
ll dp[2][N+1][N+1], ysum[N+1], xsum[N+1];
ll a[N+1];

void f() {
  int n; cin>>n;
  for (int i = 1; i <= n; i++) cin>>a[i];
  for (int i = 0; i < 2; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n; k++)
        dp[i][j][k] = 0;
  dp[0][0][0] = 1;
  xsum[0] = ysum[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int m1 = 0; m1 <= a[i]; m1++)
      dp[a[i]][]
    for (int m1 = 0; m1 <= n; m1++) {
      for (int m2 = 0; m2 <= m1; m2++) {
        if (a[i] >= m1) {
          dp[1][a[i]][m2] += dp[0][m1][m2];
          dp[1][a[i]][m2] %= MOD;
        } else if (m1 > a[i] && a[i] >= m2) {
          dp[1][m1][a[i]] += dp[0][m1][m2];
          dp[1][m1][a[i]] %= MOD;
        }
      }
    }
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n; k++) {
        dp[0][j][k] += dp[1][j][k];
        dp[0][j][k] %= MOD;
        dp[1][j][k] = 0;
      }
  }
  ll sum = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) {
      sum += dp[0][i][j];
      sum %= MOD;
    }
  cout<<sum<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
