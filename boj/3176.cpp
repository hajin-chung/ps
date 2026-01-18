#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

struct Node {
  int p, mx, mn;
};

vector<vector<pii>> adj;
Node dp[100005][30];
int chk[100005], depth[100005];
int n;

void dfs(int curr, int lev) {
  chk[curr] = 1; 
  depth[curr] = lev;
  for (auto [next, w] : adj[curr])
    if (!chk[next]) {
      dp[next][0] = {curr, w, w};
      dfs(next, lev+1);
    }
}

void lca(int a, int b) {
  int mn, mx;
  if (depth[a] < depth[b]) swap(a, b); 
  mn = mx = dp[a][0].mn;

  if (depth[a] != depth[b]) {
    for (int i = 29; i >= 0 ; i--)
      if (depth[dp[a][i].p] > depth[b]) {
        mn = min(mn, dp[a][i].mn);
        mx = max(mx, dp[a][i].mx);
        a = dp[a][i].p;
      } 
    mn = min(mn, dp[a][0].mn);
    mx = max(mx, dp[a][0].mx);
    a = dp[a][0].p;
  }

  if (a != b) {
    for (int i = 29; i >= 0 && a != b; i--)
      if (dp[a][i].p != dp[b][i].p) {
        mn = min(mn, min(dp[a][i].mn, dp[b][i].mn));
        mx = max(mx, max(dp[a][i].mx, dp[b][i].mx));
        a = dp[a][i].p;
        b = dp[b][i].p;
      }
    mn = min(mn, min(dp[a][0].mn, dp[b][0].mn));
    mx = max(mx, max(dp[a][0].mx, dp[b][0].mx));
  }
  printf("%d %d\n", mn, mx);
}

int main() {
  scanf("%d", &n);
  adj.resize(n+1);
  for (int i = 0; i < n-1; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  dfs(1, 0);
  for (int i = 1; i < 30; i++)
    for (int j = 1; j <= n; j++) {
      dp[j][i].p = dp[dp[j][i-1].p][i-1].p;
      dp[j][i].mn = min(dp[j][i-1].mn, dp[dp[j][i-1].p][i-1].mn);
      dp[j][i].mx = max(dp[j][i-1].mx, dp[dp[j][i-1].p][i-1].mx);
    }

  int m;
  scanf("%d", &m);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    lca(u, v);
  }
}
