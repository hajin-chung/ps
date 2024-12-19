#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, d; cin>>n>>d;
  vector<int> a(n), dp(n); 
  multiset<int> s;
  for (auto &ai : a) cin>>ai;
  int ans = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (i > d) {
      auto iter = s.find(dp[i-d-1]);
      if (iter != s.end()) s.erase(iter);
    }
    int mx = s.empty() ? 0 : max(0, *s.rbegin());
    dp[i] = mx + a[i];
    s.insert(dp[i]);
    ans = max(ans, dp[i]);
  }
  cout<<ans<<"\n";
}
