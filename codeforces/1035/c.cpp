#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll f() {
  ll n, l, r, k; cin>>n>>l>>r>>k;
  if (n == 2) return -1;
  if (n&1) return l;

  ll e = 1;
  for (ll t = l; t; t>>=1) e <<= 1;
  if (e > r) return -1;

  if (k <= n-2) return l;
  else return e;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) cout<<f()<<"\n";
}
