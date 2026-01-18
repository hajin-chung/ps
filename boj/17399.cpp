#include <bits/stdc++.h>
#define N 100000
#define LOGN 25
using namespace std;

int n, depth[N+5], dp[N+5][LOGN];
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
  int dab = dist(a, b);
  if (dab % 2 != 0) return -1;
  int dma = dab/2, m = a;
  for (int i = LOGN-1; i >= 0; i--)
    if (dma&(1<<i))
      m = dp[m][i];
  int dmc = dist(m, c);
  if (dmc == dma) return m;
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
    int abc = query(a, b, c), bca = query(b, c, a), cab = query(c, a, b);
    int ans = (abc != -1) ? abc : (bca != -1) ? bca : (cab != -1) ? cab : -1;
    printf("%d\n", ans);
  }
}
