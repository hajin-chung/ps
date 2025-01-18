#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  string s; cin>>s;
  vector<int> a(n);
  for (auto &x : a) cin>>x;
  vector<int> v;
  v.push_back(a[0]);
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i-1])
      v[v.size()-1] = max(v.back(), a[i]);
    else v.push_back(a[i]);
  }
  n = v.size();
  if (n == 1) { cout<<v[0]<<"\n"; return 0; }
  if (n == 2) { cout<<max(v[0], v[1])<<"\n"; return 0; }
  vector<ll> dp(n);
  dp[0] = v[0]; dp[1] = v[1]; dp[2] = (ll)v[2]+(ll)v[0];
  for (int i = 3; i < n-1; i++)
    dp[i] = (ll)v[i] + max(dp[i-2], dp[i-3]);
  cout<<*max_element(dp.begin(), dp.end())<<"\n";
}
