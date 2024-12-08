#include <bits/stdc++.h>
#define endl "\n"
#define INF 1000000000000LL
using namespace std;

typedef long long int ll;

ll mod(ll a, ll n) {
  return (a%n+n)%n;
}

ll ext_gcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1; y = 0;
    return a;
  }
  ll x1, y1;
  ll d = ext_gcd(b, a%b, x1, y1); 
  x = y1; 
  y = x1 - (a / b) * y1;
  return d;
}

pair<ll, ll> crt(ll n1, ll r1, ll n2, ll r2) {
  ll x, y;
  ll g = ext_gcd(n1, n2, x, y);
  if ((r2-r1)%g != 0) return {INF, -1};
  ll diff = (r2-r1)/g;
  ll n1p = n1 / g;
  ll n2p = n2 / g;
  ll X = r1 + x * diff * n1p;
  ll m = n1 * n2p;
  X = mod(X, m);
  return {m, X};
}

void solve(ll A, ll B, ll C, ll a, ll b, ll c) {
  auto [m1, r1] = crt(A, a, B, b); 
  if (m1 == INF && r1 == -1) {
    cout << "-1" << endl;
    return;
  }
  auto [m2, r2] = crt(m1, r1, C, c); 
  if (m2 == INF && r2 == -1) {
    cout << "-1" << endl;
    return;
  }
  cout << r2 << endl;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll t;
  cin>>t;
  while (t--) {
    ll A, B, C, a, b, c;
    cin>>A>>B>>C>>a>>b>>c;
    solve(A, B, C, a, b, c);
  }
}
