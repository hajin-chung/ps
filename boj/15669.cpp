#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int N = 100000;
vector<int> g[N+1];
int depth[N+1];
ll cnt[N+1][2];

void f(int u, int p, int lev) {
  depth[u] = lev;
  cnt[u][0] = 1;
  for (auto v : g[u])
    if (v != p) {
      f(v, u, lev+1);
      cnt[u][0] += cnt[v][1];
      cnt[u][1] += cnt[v][0];
    }
}

ll h(int u, int v, int p) {
  ll ret = cnt[u][p]-cnt[v][1-p];
  if (u != 1) ret += cnt[0][depth[u]%2!=p]-cnt[u][p];
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q; cin>>n>>q;
  for (int i = 1; i < n; i++) {
    int u, v; cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  f(1, 0, 0);
  while (q--) {
    int u, v, c; cin>>u>>v>>c;
    if (depth[u] > depth[v]) swap(u, v);
    ll ans = cnt[v][0]*h(u, v, 1-c)+cnt[v][1]*h(u, v, c);
    cout<<ans<<"\n";
  }
}
