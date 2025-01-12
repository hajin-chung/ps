#include <bits/stdc++.h>
#define MOD 40000
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<pll> fire(n);
  for (auto &[a, b] : fire)
    cin>>a>>b;
  sort(fire.begin(), fire.end(), [](pll &u, pll &v) {
    return v.fi*u.se < u.fi*v.se;
  });
  ll ans = 0, t = 0;
  for (int i = 0; i < n; i++) {
    ans += fire[i].fi*ans+fire[i].se;
    ans %= MOD;
  }
  cout<<ans<<"\n";
}
