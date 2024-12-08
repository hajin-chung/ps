#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll mod(ll a, ll n) {
  return (a%n+n)%n;
}

ll gcd(ll a, ll b) {
  return b ? gcd(b, a%b) : a;
}

ll ext_gcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1; y = 0;
    return a;
  }
  ll x1, y1;
  ll d = ext_gcd(b, a%b, x1, y1);
  x = y1;
  y = x1 - y1 * (a/b);
  return d;
}

void solve() {
  ll k, c;
  cin>>k>>c;
  if (k == 1 && c == 1) {
    cout<<2<<"\n";
    return;
  } else if (c == 1) {
    if (k + 1 > 1e9) cout << "IMPOSSIBLE\n";
    else cout << k+1 << "\n";
    return;
  } else if (k == 1) {
    cout << 1 << "\n";
    return;
  } else if (gcd(k, c) != 1) {
    cout << "IMPOSSIBLE\n";
    return;
  } 
  ll x, y;
  ext_gcd(c, k, x, y);
  cout << mod(x, k) << endl;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll t;
  cin>>t;
  while (t--) solve();
}
