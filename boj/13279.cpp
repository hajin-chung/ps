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
    if (i) dp[i] += dp[i-1];
  }
  ans[0] = dp[n-1];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n-i; j++)
      dp[j] = (dp[j]*a[j+i]+(j?dp[j-1]:0LL))%MOD;
    ans[i] = dp[n-1-i];
  }
  int q; cin>>q;
  while (q--) {
    int x; cin>>x; cout<<ans[x-1]<<"\n";
  }
}
