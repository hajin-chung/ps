#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
const ll MOD = 998244353;
const int INF = 1e9;
ll c[55][55];

ll fact(int n) {
  ll ret = 1;
  for (ll i = 1; i <= n; i++) ret = (ret*i)%MOD;
  return ret;
}

ll f() {
  int n; cin>>n;
  vector<int> a(n+1);
  for (auto &x: a) cin>>x;

  // cerr<<"==========\n";
  if (n == 1) return 1;
  while (1) {
    int zcnt = 0; for (int i = 1; i <= n; i++) zcnt += a[i] == 0;
    int ocnt = 0; for (int i = 1; i <= n; i++) ocnt += a[i] == 1;
    int mn = INF; for (int i = 1; i <= n; i++) if (a[i] != 0) mn = min(mn, a[i]);
    int mx = 0; for (int i = 1; i <= n; i++) mx = max(mx, a[i]);
    int mxcnt = 0; for (int i = 1; i <= n; i++) mxcnt += a[i] == mx;

    if (mx == 1) {
      if (a[0] >= zcnt) return fact(n);
      return (c[zcnt][a[0]]*fact(ocnt+a[0])%MOD)*fact(zcnt-a[0])%MOD;
    } else if (mx == 0) {
      return fact(n);
    }

    int sub = mn;
    if (mxcnt == n-zcnt) sub = mx-1;
    for (int i = 1; i <= n; i++) {
      if (a[i] == 0) a[0] -= sub;
      else a[i] -= sub;
    }

    if (a[0] < 0) return 0;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  c[1][0] = 1;
  c[1][1] = 1;
  for (int i = 2; i <= 50; i++)
    for (int j = 0; j <= i; j++)
      c[i][j] = (c[i-1][j] + (j == 0 ? 0 : c[i-1][j-1])) % MOD;
  int t; cin>>t;
  while (t--) cout<<f()<<"\n";
}
