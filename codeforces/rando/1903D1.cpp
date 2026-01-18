#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

typedef uint64_t ll;
const int N = 1e5;
int n;
ll a[N+1];
ll b[N+1];

ll cut(ll x, int len) {
  return x & ((1LL<<len)-1);
}

void g() {
  ll k; cin>>k;
  for (int i = 1; i <= n; i++) b[i] = a[i];
  ll ans = 0;
  for (int i = 60; i >= 0; i--) {
    ll cnt = 0; 
    ll bit = (1LL<<i);
    bool flag = 0;
    for (int j = 1; j <= n; j++) {
      if ((b[j] & bit) > 0) continue;
      if (bit-cut(b[j], i) > k-cnt) flag = 1;
      cnt += bit - cut(b[j], i);
    }
    if (cnt > k || flag) continue; 
    k -= cnt;
    ans += bit;
    for (int j = 1; j <= n; j++) {
      if ((b[j] & bit) > 0) continue;
      b[j] += bit - cut(b[j], i);
    }
  }
  cout<<ans<<"\n";
}

void f() {
  int q; cin>>n>>q;
  for (int i = 1; i <= n; i++) cin>>a[i];
  while (q--) g();
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  f();
}
