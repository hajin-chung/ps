#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); 
  int n; cin>>n;
  vector<ll> a(n); for (auto &ai : a) cin>>ai;
  a.push_back(0);
  ll ans = 0;
  stack<int> s;
  for (int i = 0; i <= n; i++) {
    while (!s.empty() && a[s.top()] >= a[i]) {
      int k = s.top(); s.pop();
      ll w = s.empty() ? i : i-k+1;
      ans = max(ans, w * a[k]);
    }
    s.push(i);
  }
  cout<<ans<<"\n";
}
