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
    return u.fi * v.se > v.fi * u.se;
  });
  ll t = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    ll ft = (fire[i].fi*t+fire[i].se)%MOD;
    ans = (ans+ft)%MOD;
    t = ans;
  }
  cout<<ans<<"\n";
}
