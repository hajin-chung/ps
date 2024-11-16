#include <bits/stdc++.h>
#define fi first
#define se second
#define INF 1000000000
#define N 100000
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
struct Seg {
  int tree[1<<18];
  int sz = 1<<17;

  void update(int idx, int val) {
    idx |= sz; tree[idx] = val;
    while (idx>>=1) 
      tree[idx] = max(tree[idx<<1], tree[idx<<1|1]);
  }

  int query(int l, int r) {
    l |= sz; r |= sz;
    int ret = 0;
    while (l <= r) {
      if (l&1) ret = max(ret, tree[l++]);
      if (~r&1) ret = max(ret, tree[l--]);
      l>>=1; r>>=1;
    }
    return ret;
  }
} seg;
int n;
int sz[N+1], dep[N+1], par[N+1], top[N+1], in[N+1], out[N+1], weights[N+1];
vector<int> g[N+1];
vector<pii> adj[N+1];
vector<pii> edges;

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

void update(int u, int w) { seg.update(in[u], w); }

int query(int a, int b) {
  int ret = 0;
  while (top[a] != top[b]) {
    if (dep[top[a]] < dep[top[b]]) swap(a, b);
    int st = top[a];
    ret = max(ret, seg.query(in[st], in[a]));
    a = par[st];
  }
  if (dep[a] > dep[b]) swap(a, b);
  ret = max(ret, seg.query(in[a], in[b]));
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  for (int i = 0; i < n-1; i++) {
    int u, v, w;
    cin>>u>>v>>w;
    edges.push_back({u, v});
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  dfs(1); dfs1(1); dfs(1);
  for (int i = 2; i <= n; i++)
    seg.update(in[i], weights[i]);
  int t;
  cin>>t;
  while (t--) {
    int q, u, v;
    cin>>q>>u>>v;
    if (q == 1) {
      auto [a, b] = edges[u];
      cout << "hi" << endl;
      if (dep[a] < dep[b]) swap(a, b);
      seg.update(in[a], v);
    } else {
      cout << query(u, v) << "\n";
    }
  }
}
