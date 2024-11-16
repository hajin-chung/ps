#include <bits/stdc++.h>
#define fi first
#define se second
#define INF 1000000000
#define N 100000
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
int n;
int sz[N+1], dep[N+1], par[N+1], top[N+1], in[N+1], out[N+1], weights[N+1];
vector<int> g[N+1];
vector<pii> adj[N+1];
vector<ppi> edges;
int tree[4*N];

int update(int node, int l, int r, int idx, int v) {
  if (idx < l || r < idx) return tree[node];
  if (l == r) return tree[node] = v;
  int m = (l+r)>>1;
  return tree[node] = max(
    update(node*2, l, m, idx, v),
    update(node*2+1, m+1, r, idx, v)
  );
}

int query(int node, int l, int r, int ql, int qr) {
  if (qr < l || r < ql) return -INF;
  if (ql <= l && r <= qr) return tree[node];
  int m = (l+r)>>1;
  return max(
    query(node*2, l, m, ql, qr),
    query(node*2+1, m+1, r, ql, qr)
  );
}

int chk[N+1];
void dfs(int u) {
  chk[u] = 1;
  for (auto [v, w] : adj[u])
    if (!chk[v]) {
      chk[v] = 1;
      weights[v] = w;
      g[u].push_back(v);
      dfs(v);
    }
}

void dfs1(int u) {
  sz[u] = 1;
  for (auto &v : g[u]) {
    dep[v] = dep[u]+1; par[v] = u;
    dfs1(v); sz[u] += sz[v];
    if (sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
  }
}

int pv;
void dfs2(int u) {
  in[u] = ++pv;
  for (auto v : g[u]) {
    top[v] = v == g[u][0] ? top[u] : v;
    dfs2(v);
  }
  out[u] = pv;
}

int solve(int a, int b) {
  int ret = 0;
  while (top[a] != top[b]) {
    if (dep[top[a]] < dep[top[b]]) swap(a, b);
    int st = top[a];
    ret = max(ret, query(1, 1, n, in[st], in[a]));
    a = par[st];
  }
  if (dep[a] > dep[b]) swap(a, b);
  ret = max(ret, query(1, 1, n, in[a], in[b]));
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  for (int i = 0; i < n-1; i++) {
    int u, v, w;
    cin>>u>>v>>w;
    edges.push_back({{u, v}, w});
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  dfs(1); dfs1(1); dfs2(1);
  for (auto &[uv, w] : edges) {
    auto &[u, v] = uv;
    if (par[v] == u) swap(u, v);
    update(1, 1, n, in[u], w);
  }
  int t;
  cin>>t;
  while (t--) {
    int op; cin>>op;
    if (op == 1) {
      int i, c; cin>>i>>c;
      update(1, 1, n, edges[i-1].fi.fi, c);
    } else {
      int u, v; cin>>u>>v;
      cout << solve(u, v) << "\n";
    }
  }
}
