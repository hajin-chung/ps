#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<pll> a(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    ll w, s; cin>>w>>s;
    a[i] = {w, s};
    sum += w;
  }
  sort(a.begin(), a.end(), [](pll u, pll v) { return u.fi+u.se > v.fi+v.se; });
  ll mx = sum-a[0].fi-a[0].se;
  for (auto [w, s] : a) {
    mx = max(mx, sum-w-s);
    sum -= w;
  }
  cout<<mx<<"\n";
}
