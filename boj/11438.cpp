#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<vector<int>> dp, adj, tree;
vector<int> depth, check;
int n, m;

void make_tree(int curr) {
  check[curr] = true; 
  for (auto next : adj[curr])
    if (check[next] == 0) {
      tree[curr].push_back(next);
      make_tree(next);
    }
}

void dfs(int curr, int parent, int lev) {
  depth[curr] = lev;

  if (lev > 0) {
    dp[curr].resize((int)floor(log2(lev)) + 1);
    dp[curr][0] = parent;
    for (int i = 1; i < dp[curr].size(); i++) 
      dp[curr][i] = dp[dp[curr][i-1]][i-1];
  }

  for (auto next : tree[curr]) 
    dfs(next, curr, lev+1);
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
  int i;
  int x, y, z;

  scanf("%d", &n);
  adj.resize(n+1);
  check.resize(n+1);
  tree.resize(n+1);
  dp.resize(n+1);
  depth.resize(n+1);
  for (i = 0; i < n-1; i++) {
    scanf("%d %d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  make_tree(1);
  dfs(1, 0, 0);

  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    printf("%d\n", lca(x, y));
  }
}
