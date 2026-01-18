#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, pii> plp;

int find(int u, vector<int> &p) {
  if (p[u] == u) return u;
  return p[u] = find(p[u], p);
}

void merge(int u, int v, vector<int> &p) {
  u = find(u, p); v = find(v, p);
  if (u < v) p[v] = u;
  else p[u] = v;
}

void solve() {
  int n, m; cin>>n>>m;
  vector<int> p(n);
  vector<plp> edges;
  for (int i = 1; i < n; i++) {
    int v; ll w; cin>>v>>w;
    edges.push_back({w, {i, v}});
  }
  ll ans = -1;
  while (m--) {
    int u, v; ll w; cin>>u>>v>>w;
    edges.push_back({w, {u, v}});
    sort(edges.begin(), edges.end());
    for (int i = 0; i < n; i++) p[i] = i;
    ll mst = 0;
    for (auto [w, uv] : edges) {
      auto [u, v] = uv;
      if (find(u, p) == find(v, p)) continue;
      merge(u, v, p);
      mst += w;
    }
    if (ans == -1) ans = mst;
    else ans ^= mst;
  }
  cout<<ans<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) solve();
}
