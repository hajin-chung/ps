#include <bits/stdc++.h>
#define N 50005
#define INF (1<<31)-1
using namespace std;

typedef long long int ll;
typedef pair<int, ll> pil;
typedef pair<ll, pair<int, int>> plp;
struct node {
  int nxt;
  ll m1;
  ll m2;
};
int n, m;
vector<plp> edges;
vector<bool> used;
vector<vector<pil>> adj;
node dp[N][25];
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
  for (auto [nxt, w] : adj[curr])
    if (!chk[nxt]) {
      dfs(nxt, lev+1);
      dp[nxt][0] = {curr, w, 0};
    }
}

pair<ll, ll> lca(int u, int v) {
  set<ll> ret;
  if (depth[u] < depth[v]) swap(u, v);
  for (int i = 24; i >= 0; i--)
    if (depth[dp[u][i].nxt] >= depth[v]) {
      ret.insert(dp[u][i].m1);
      ret.insert(dp[u][i].m2);
      u = dp[u][i].nxt;
      while (ret.size() > 2) ret.erase(ret.begin());
    }
  if (u == v) {
    if (ret.size() == 1) return {*ret.begin(), -1};
    else return {*next(ret.begin()), *ret.begin()};
  }
  for (int i = 24; i >= 0; i--)
    if (dp[u][i].nxt != dp[v][i].nxt) {
      ret.insert(dp[u][i].m1);
      ret.insert(dp[u][i].m2);
      ret.insert(dp[v][i].m1);
      ret.insert(dp[v][i].m2);
      u = dp[u][i].nxt;
      v = dp[v][i].nxt;
      while (ret.size() > 2) ret.erase(ret.begin());
    }
  ret.insert(dp[u][0].m1);
  ret.insert(dp[u][0].m2);
  ret.insert(dp[v][0].m1);
  ret.insert(dp[v][0].m2);
  if (ret.size() == 1) return {*ret.begin(), -1};
  else return {*next(ret.begin()), *ret.begin()};
}

int main() {
  scanf("%d %d", &n, &m);
  adj.resize(n+1);
  used.resize(m);
  for (int i = 1; i <= n; i++) p[i] = i;
  for (int i = 0; i < m; i++) {
    int u, v;
    ll w;
    scanf("%d %d %lld", &u, &v, &w);
    edges.push_back({w, {u, v}});
  }
  sort(edges.begin(), edges.end());
  ll mst = 0;
  int cnt = 0;
  for (int i = 0; i < edges.size(); i++) {
    auto [w, pp] = edges[i];
    auto [u, v] = pp;
    if (find(u) == find(v)) continue;
    merge(u, v);
    mst += w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
    cnt++;
    used[i] = true;
  }
  if (cnt != n-1) {
    printf("-1\n");
    return 0;
  }

  depth[0] = -1;
  dfs(1, 0);
  for (int i = 1; i < 25; i++)
    for (int j = 1; j <= n; j++) {
      set<ll> ret;
      int nxt = dp[j][i-1].nxt;
      ret.insert(dp[j][i-1].m1);
      ret.insert(dp[j][i-1].m2);
      ret.insert(dp[nxt][i-1].m1);
      ret.insert(dp[nxt][i-1].m2);
      while (ret.size() > 2) ret.erase(ret.begin());
      dp[j][i].nxt = dp[nxt][i-1].nxt;
      dp[j][i].m1 = *next(ret.begin());
      if (ret.size() >= 2) dp[j][i].m2 = *ret.begin();
    }

  ll ans = INF;
  for (int i = 0; i < edges.size(); i++) {
    if (used[i]) continue;
    auto [w, pp] = edges[i];
    auto [u, v] = pp;
    auto [m1, m2] = lca(u, v);
    if (m1 != w) ans = min(ans, mst - m1 + w);
    if (m2 != -1) ans = min(ans, mst - m2 + w);
  }
  if (ans == INF) printf("-1\n");
  else printf("%lld\n", ans);
}
