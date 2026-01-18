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

int main() {
  ll n, a, x, y;
  cin>>n>>a;
  ll g = ext_gcd(n, a, x, y);
  y = mod(y, n);
  cout<<n-a<<" ";
  if (g != 1) cout<<"-1\n";
  else cout << y << "\n";
}
