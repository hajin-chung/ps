#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int M = 10000;
typedef long long int ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin>>n>>m;
  vector<ll> dp(m+1, -1);
  dp[0] = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    auto tmp = dp;
    ll v, c, k; cin>>v>>c>>k;
    for (int ki = 1; ki <= k; ki++)
      for (int j = v*ki; j <= m; j++)
        if (dp[j-v*ki] != -1 && dp[j] < dp[j-v*ki]+c*ki) {
          tmp[j] = dp[j-v*ki] + c*ki;
          ans = max(ans, tmp[j]);
        }
    dp = tmp;
  }
  for (int i = 1; i <= m; i++) cout<<dp[i]<<" ";
  cout<<"\n";
  cout<<ans<<"\n";
}
