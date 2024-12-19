#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; ll l; cin>>n>>l;
  vector<ll> a(n);
  vector<bool> chk(n);
  for (auto &ai : a) cin>>ai;
  ll ans = 0, dist = 0;
  for (int i = 0; i < n; i++) {
    ll mn = LLONG_MAX; int idx;
    for (int j = 0; j < n; j++)
      if (!chk[j] && abs(l-a[j]) < mn) {
        mn = abs(l-a[j]);
        idx = j;
      }
    l = a[idx];
    dist += mn;
    ans += dist;
    chk[idx] = true;
  }
  cout<<ans<<"\n";
}
