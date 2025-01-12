#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef pair<ll, int> pli;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<ll> a(n);
  vector<pli> pairs;
  for (int i = 0; i < n; i++) {
    ll x; cin>>x;
    a[i] = x;
    pairs.push_back({x, i});
  }
  sort(pairs.begin(), pairs.end());
  ll mn = pairs[0].fi, ans = 0;
  vector<bool> chk(n, 0);
  for (int u = 0; u < n; u++) {
    if (chk[u]) continue;
    ll cmn = pairs[u].fi, csum = 0, cnt = 0;
    while (!chk[u]) {
      cnt++;
      chk[u] = 1;
      csum += pairs[u].fi;
      u = pairs[u].se;
    }
    ans += min(csum-cmn+(cnt-1)*cmn, csum-cmn+(cnt-1)*mn+2*(cmn+mn));
  }
  cout<<ans<<"\n";
}
