#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<vector<int>> adj;
int n;
int dp[100005][30], depth[100005];
bool chk[100005];

void dfs(int curr, int lev) {
  chk[curr] = true;
  depth[curr] = lev; 
  for (auto next : adj[curr]) 
    if (!chk[next]) {
      dp[next][0] = curr;
      dfs(next, lev+1);
    }
}

int lca(int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);
  for (int i = 29; i >= 0; i--)
    if (depth[dp[a][i]] >= depth[b])
      a = dp[a][i];
  if (a == b) return a;
  for (int i = 29; i >= 0; i--)
    if (dp[a][i] != dp[b][i]) {
      a = dp[a][i];
      b = dp[b][i];
    }
  return dp[a][0];
}

int lca(int r, int a, int b) {
  int ra = lca(r, a);
  int rb = lca(r, b);
  int ab = lca(a, b);
  pii ret = {depth[ra], ra};
  ret = max(ret, {depth[rb], rb});
  ret = max(ret, {depth[ab], ab});
  return ret.second;
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
  dfs(1, 0);
  for (int i = 1; i < 30; i++)
    for (int j = 1; j <= n; j++)
      dp[j][i] = dp[dp[j][i-1]][i-1];
  int m;
  scanf("%d", &m);
  while (m--) {
    int r, a, b;
    scanf("%d %d %d", &r, &a, &b);
    printf("%d\n", lca(r, a, b));
  }
}
