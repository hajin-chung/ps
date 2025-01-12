#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int M = 10000;
const int C = 10000;
typedef long long int ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin>>n>>m;
  vector<ll> dp(M+1, -1);
  dp[0] = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll v, c, k; cin>>v>>c>>k;
    ll t = 1;
    while (k) {
      int tt = min(k, t);
      for (int j = m; j >= v*tt; j--)
        if (dp[j] < dp[j-v*tt]+c*tt) {
          dp[j] = dp[j-v*tt]+c*tt;
          ans = max(ans, dp[j]);
        }
      t <<= 1;
      k -= tt;
    }
  }
  cout<<ans<<"\n";
}
