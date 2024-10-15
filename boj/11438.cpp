#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<vector<int>> dp, adj;
vector<int> depth, check;
int n, m;

void dfs(int curr = 1, int lev = 0) {
  check[curr] = 1;
  depth[curr] = lev;
  dp[curr].resize(40);
  for (auto next : adj[curr])
    if (!check[next]) {
      dp[next][0] = curr;
      dfs(next, lev+1);
    }
}

int lca(int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);
  int diff = depth[a] - depth[b];
  for (int i = 0; diff; i++) {
    if (diff & 1) a = dp[a][i];
    diff >>= 1;
  }

  if (a == b) return a;

  for (int i = dp[a].size() - 1; i >= 0; i--)
    if (dp[a][i] != dp[b][i]) {
      a = dp[a][i], b = dp[b][i];
    }
  return dp[a][0];
}

int main() {
  int i, j;
  int x, y, z;

  scanf("%d", &n);
  adj.resize(n+1);
  check.resize(n+1);
  dp.resize(n+1, vector<int>(30));
  depth.resize(n+1);
  for (i = 0; i < n-1; i++) {
    scanf("%d %d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  dfs();
  for (j = 1; j < 30; j++) 
    for (i = 1; i <= n; i++)
      dp[i][j] = dp[dp[i][j-1]][j-1];

  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    printf("%d\n", lca(x, y));
  }
}
