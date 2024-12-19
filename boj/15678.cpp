#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, d; cin>>n>>d;
  vector<int> a(n), dp(n); 
  multiset<int> s;
  for (auto &ai : a) cin>>ai;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int mx; if (!s.empty()) mx = *s.rbegin();
    if (!s.empty() && mx >= 0) dp[i] = mx + a[i];
    else dp[i] = a[i];
    if (i >= d) {
      auto iter = s.find(dp[i-d]);
      if (iter != s.end()) s.erase(iter);
    }
    s.insert(dp[i]);
    ans = max(ans, dp[i]);
  }
  cout<<ans<<"\n";
}
