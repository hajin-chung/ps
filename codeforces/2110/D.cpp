#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

typedef int64_t ll;
const ll MAXW = 2e14;
const int N = 2e5;
int n;
ll b[N+1];
vector<pair<int, ll>> g[N+1];

bool check(ll maxb) {
  vector<ll> bsum(n+1);
  vector<ll> chk(n+1);
  vector<int> idg(n+1);
  for (int i = 1; i <= n; i++) 
    for (auto [v, w] : g[i])
      idg[v]++;

  chk[1] = 1;
  bsum[1] = min(maxb, b[1]);
  for (int u = 1; u <= n; u++) {
    if (!chk[u]) continue;
    for (auto [v, w] : g[u]) {
      if (bsum[u] < w) continue;
      chk[v] = 1;
      bsum[v] = max(bsum[v], min(bsum[u] + b[v], maxb));
    }
  }
  return chk[n];
}

void f() {
  int m; cin>>n>>m;
  for (int i = 1; i <= n; i++) cin>>b[i];
  for (int i = 1; i <= n; i++) g[i].clear();
  for (int i = 1; i <= m; i++) {
    int u, v; ll w; cin>>u>>v>>w;
    g[u].push_back({v, w});
  }

  ll l = 0, r = MAXW;
  while (l < r) {
    ll m = (l+r)>>1;
    bool flag = check(m);
    if (flag) r = m;
    else l = m+1;
  }

  if (l == MAXW) {
    cout<<"-1\n";
  } else {
    cout<<l<<"\n";
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
