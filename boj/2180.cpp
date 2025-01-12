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
  sort(fire.begin(), fire.end(), [](pll &u, pll &v) {
    return v.fi*u.se < u.fi*v.se;
  });
  ll t = 0;
  for (int i = 0; i < n; i++) {
    t += fire[i].fi*t+fire[i].se;
    t %= MOD;
  }
  cout<<t<<"\n";
}
