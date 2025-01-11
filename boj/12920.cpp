#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int C = 10000;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin>>n>>m;
  vector<int> dp(C+1, INF);
  dp[0] = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    auto tmp = dp;
    int v, c, k; cin>>v>>c>>k;
    for (int ki = 1; ki <= k; ki++)
      for (int u = c*ki; u <= 10000; u++)
        if (dp[u-c*ki] != -1 && dp[u-c*ki] + v*ki <= m && dp[u] > dp[u-c*ki]+v*ki) {
          tmp[u] = dp[u-c*ki] + v*ki;
          ans = max(ans, u);
        }
    dp = tmp;
  }
  cout<<ans<<"\n";
}
