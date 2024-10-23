#include <bits/stdc++.h>
#define fi first
#define se second
#define N 50005
#define INF (1<<31)-1;
using namespace std;

typedef long long int ll;
typedef pair<int, ll> pil;
typedef pair<ll, pair<int, int>> plp;
int n, m;
vector<plp> edges, sorted;
vector<vector<pil>> adj;
pil dp[N][25];
int p[N], depth[N];
bool chk[N];

int find(int u) {
  if (p[u] == u) return u;
  return p[u] = find(p[u]);
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u < v) p[v] = u;
  else p[u] = v;
}

void dfs(int curr, int lev) {
  chk[curr] = true;
  depth[curr] = lev;
  for (auto [next, w] : adj[curr])
    if (!chk[next]) {
      dfs(next, lev+1);
      dp[next][0] = {curr, w};
    }
}

ll lca(int u, int v) {
  ll ret = 0;
  if (depth[u] < depth[v]) swap(u, v);
  for (int i = 24; i >= 0; i--)
    if (depth[dp[u][i].fi] >= depth[v]) {
      ret = max(ret, dp[u][i].se);
      u = dp[u][i].fi;
    }
  if (u == v) return ret;
  for (int i = 24; i >= 0; i--)
    if (dp[u][i].fi != dp[v][i].fi) {
      ret = max(ret, max(dp[u][i].se, dp[v][i].se));
      u = dp[u][i].fi;
      v = dp[v][i].fi;
    }
  ret = max(ret, max(dp[u][0].se, dp[v][0].se));
  return ret;
}

int main() {
  scanf("%d %d", &n, &m);
  adj.resize(n+1);
  for (int i = 1; i <= n; i++) p[i] = i;
  for (int i = 0; i < m; i++) {
    int u, v;
    ll w;
    scanf("%d %d %lld", &u, &v, &w);
    edges.push_back({w, {u, v}});
  }
  sorted = edges;
  sort(sorted.begin(), sorted.end());
  ll mst = 0;
  int cnt = 0;
  for (auto edge : sorted) {
    auto [w, pp] = edge;
    auto [u, v] = pp;
    if (find(u) == find(v)) continue;
    merge(u, v);
    mst += w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
    cnt++;
  }
  if (cnt != n-1) {
    printf("-1\n");
    return 0;
  }

  depth[0] = -1;
  dfs(1, 0);
  for (int i = 1; i < 25; i++)
    for (int j = 1; j <= n; j++) {
      int next = dp[j][i-1].fi;
      dp[j][i].fi = dp[next][i-1].fi;
      dp[j][i].se = max(dp[j][i-1].se, dp[next][i-1].se);
    }

  ll smst = INF;
  for (auto edge : edges) {
    auto [w, pp] = edge;
    auto [u, v] = pp;
    ll nmst = mst - lca(u, v) + w;
    if (nmst != mst) smst = min(smst, nmst); 
  }
  if (smst == INF) printf("-1\n");
  else printf("%lld\n", smst);
}
