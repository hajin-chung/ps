#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll INF = 1e14;
const int N = 200000;

ll dp[N+1][5];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<ll> a(n+1), sum(n+1);
  for (int i = 1; i <= n; i++) {
    cin>>a[i];
    sum[i] = a[i]^sum[i-1];
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= min(i, 4); j++) {
      ll xr = i == j ? sum[i] : sum[i]^sum[i-j], mx = 0;
      for (int k = 1; k <= 4; k++) {
        if (j == k) continue;
        mx = max(mx, dp[i-j][k]);
      }
      dp[i][j] = mx + xr;
    }
  ll ans = 0;
  for (int i = 1; i <= 4; i++)
    ans = max(ans, dp[n][i]);
  cout<<ans<<"\n";
}
