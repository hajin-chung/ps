#include <bits/stdc++.h>
#define N 100000
#define LOGN 20
using namespace std;

int n, p[N+5], depth[N+5], dp[N+5][LOGN];
bool chk[N+5];
vector<vector<int>> adj;

void dfs(int u, int lev = 0) {
  chk[u] = true;
  depth[u] = lev;
  for (auto v : adj[u])
    if (!chk[v]) {
      dp[v][0] = u;
      dfs(v, lev+1);
    }
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  for (int i = LOGN-1; i >= 0; i--)
    if (depth[dp[u][i]] >= depth[v])
      u = dp[u][i];
  if (u == v) return u;
  for (int i = LOGN-1; i >= 0; i--)
    if (dp[u][i] != dp[v][i]) {
      u = dp[u][i];
      v = dp[v][i];
    }
  return dp[u][0];
}

int dist(int u, int v) {
  int ca = lca(u, v); 
  return depth[u] + depth[v] - 2*depth[ca];
}

int query(int a, int b, int c) {
  if (depth[a] < depth[b]) swap(a, b);
  int dab = dist(a, b), cab = lca(a, b);
  if (dab % 2 != 0) return -1;
  int m = a;
  for (int i = LOGN-1; i >= 0; i--)
    if ((dab/2)&(1<<i))
      m = dp[a][i];
  int dmc = dist(m, c);
  if (dmc == dab/2) return m;
  return -1;
}

int main() {
  scanf("%d", &n);
  adj.resize(n+1);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  depth[0] = -1;
  dfs(1);
  for (int i = 1; i < LOGN; i++)
    for (int j = 1; j <= n; j++)
      dp[j][i] = dp[dp[j][i-1]][i-1];

  int m;
  scanf("%d", &m);
  while (m--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int ans = -1;
    ans = max(ans, query(a, b, c));
    ans = max(ans, query(b, c, a));
    ans = max(ans, query(c, a, b));
    printf("%d\n", ans);
  }
}
