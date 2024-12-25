#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
map<pll, int> dp;

ll f(ll x, ll y) {
  if (x == 0 && y == 0) return 0; 
  if (dp.count({x, y})) return dp[{x, y}];
  ll ret = 0;
  for (int i = 1; i <= 40; i++) {
    ll s = (1LL<<i)-1;
    ll e = (1LL<<(i+1))-2;
    s = max(s, x); e = min(e, y);

    ll ss = s - (1LL<<i) + 1;
    ll ee = e - (1LL<<i) + 1;
    if (s <= e) ret = max(ret, i + f(ss, ee));
  }
  return dp[{x, y}] = ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) {
    ll x, y; cin>>x>>y;
    cout<<f(x, y)<<"\n";
  }
}
