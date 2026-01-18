#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, d; cin>>n>>d;
  vector<ll> a(n), dp(n); 
  multiset<ll> s;
  for (auto &ai : a) cin>>ai;
  ll ans = LLONG_MIN;
  for (int i = 0; i < n; i++) {
    ll mx = s.empty() ? 0 : max((ll)0, *s.rbegin());
    dp[i] = mx + a[i];
    if (i >= d) {
      auto iter = s.find(dp[i-d]);
      if (iter != s.end()) s.erase(iter);
    }
    s.insert(dp[i]);
    ans = max(ans, dp[i]);
  }
  cout<<ans<<"\n";
}
