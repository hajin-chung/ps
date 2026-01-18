#include <bits/stdc++.h>
#define MOD 1000000007
#define N 4000000
using namespace std;

typedef long long int ll;
ll fact[N+1], invfact[N+1];

ll extgcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1; y = 0;
    return a;
  }
  ll x1, y1;
  ll d = extgcd(b, a%b, x1, y1);
  x = y1;
  y = x1-y1*(a/b);
  return d;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  fact[0] = invfact[0] = 1;
  for (int i = 1; i <= N; i++) {
    ll x, y;
    extgcd(i, MOD, x, y); 
    ll inv = (x+MOD)%MOD;
    invfact[i] = (invfact[i-1]*inv)%MOD;
    fact[i] = (fact[i-1]*i)%MOD;
  }
  int t; cin>>t;
  while (t--) {
    int n, k; cin>>n>>k;
    ll ans = (((fact[n]*invfact[k])%MOD)*invfact[n-k])%MOD;
    cout<<ans<<"\n";
  }
}
