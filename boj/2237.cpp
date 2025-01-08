#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, t; cin>>n>>t;
  vector<int> a(n);
  for (auto &i : a) cin>>i;
  map<int, int> mp[100];
  if (n == 1) return 0;
  mp[0][a[0]] = -10;
  mp[1][a[0] - a[1]] = -a[1];
  for (int i = 2; i < n; i++)
    for (auto [u, _] : mp[i-1]) {
      mp[i][u+a[i]] = a[i];
      mp[i][u-a[i]] = -a[i];
    }
  int cnt = 0, u = t, mcnt = 0;
  for (int i = n-1; i >= 1; i--) {
    if (mp[i][u] > 0) cnt++;
    else {
      while (cnt--) cout<<i+1<<"\n";
      cnt = 0;
      mcnt++;
    }
    u -= mp[i][u];
  }
  while (mcnt--) cout<<1<<"\n";
}
