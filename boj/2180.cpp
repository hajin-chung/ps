#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef unsigned long long int ll;
typedef pair<ll, ll> pll;
const ll MOD = 40000;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<pll> fire(n);
  for (auto &[a, b] : fire)
    cin>>a>>b;
  sort(fire.begin(), fire.end(), [](pll &u, pll &v) -> bool {
    if(u.se == 0 && v.se == 0) return 0;
    if(u.se == 0) return 1;
    if(v.se == 0) return 0;
    return u.fi * v.se > v.fi * u.se;
  });
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll ft = (fire[i].fi*ans+fire[i].se)%MOD;
    ans = (ans+ft)%MOD;
  }
  cout<<ans<<"\n";
}
