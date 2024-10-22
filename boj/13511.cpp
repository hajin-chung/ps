#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef pair<int, ll> pil;

int n;
vector<vector<pil>> adj;
pil dp[100005][30];
int depth[100005];
bool chk[100005];

void dfs(int curr, int lev) {
  chk[curr] = true;
  depth[curr] = lev;
  for (auto [next, w] : adj[curr])
    if (!chk[next]) {
      dfs(next, lev+1);
      dp[next][0] = {curr, w};
    }
}

pil lca(int a, int b) {
  ll ret = 0;
  if (depth[a] < depth[b]) swap(a, b);
  for (int i = 29; i >= 0; i--)
    if (depth[dp[a][i].fi] >= depth[b]) {
      ret += dp[a][i].se;
      a = dp[a][i].fi; 
    }
  if (a == b) return {a, ret};
  for (int i = 29; i >= 0; i--)
    if (dp[a][i].fi != dp[b][i].fi) {
      ret += (dp[a][i].se + dp[b][i].se);
      a = dp[a][i].fi, b = dp[b][i].fi;
    }
  ret += (dp[a][0].se + dp[b][0].se);
  return {dp[a][0].fi, ret};
}

int query(int a, int b, int k) {
  auto [anc, d] = lca(a, b);
  int dpth;
  if (depth[a] - depth[anc] >= k) {
    dpth = depth[a] - k;
  } else {
    k = (depth[a]-depth[anc])+(depth[b]-depth[anc]) - k;
    dpth = depth[b] - k;
    swap(a, b);
  }
  for (int i = 29; i >= 0; i--)
    if (depth[dp[a][i].fi] >= dpth)
      a = dp[a][i].fi;
  return a;
}

int main() {
  scanf("%d", &n);
  adj.resize(n+1);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    ll w;
    scanf("%d %d %lld", &u, &v, &w);
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  depth[0] = -1;
  dfs(1, 0);
  for (int i = 1; i < 30; i++)
    for (int j = 1; j <= n; j++) 
      dp[j][i] = {
        dp[dp[j][i-1].fi][i-1].fi, 
        dp[dp[j][i-1].fi][i-1].se + dp[j][i-1].se
      };
  int m;
  scanf("%d", &m);
  while (m--) {
    int q, u, v, k;
    scanf("%d", &q);
    if (q == 1) {
      scanf("%d %d", &u, &v);
      printf("%lld\n", lca(u, v).se);
    } else {
      scanf("%d %d %d", &u, &v, &k);
      printf("%d\n", query(u, v, k-1));
    }
  }
}
