#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve() {
  int n; cin>>n;
  vector<int> d;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x; cin>>x;
    if (d.empty() || d.back() < x) {
      d.push_back(x);
      ans++;
    } else {
      auto it = lower_bound(d.begin(), d.end(), x);
      *it = x;
    }
  }
  cout<<ans<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) solve();
}
