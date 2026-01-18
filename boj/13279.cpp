#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int N = 30000;
const ll MOD = 100003;
ll ans[N], dp[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin>>a[i];
    dp[i] = a[i];
    ans[0] += a[i];
  }
  for (int i = 1; i < n; i++) {
    ll p = 0;
    for (int j = 0; j < n-i; j++) {
      p += dp[j]; p %= MOD;
      ans[i] += p*a[i+j]%MOD; ans[i] %= MOD;
      dp[j] = p*a[i+j]%MOD;
    }
  }
  int q; cin>>q;
  while (q--) {
    int x; cin>>x; cout<<ans[x-1]<<"\n";
  }
}
