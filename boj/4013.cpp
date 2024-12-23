#include <bits/stdc++.h>
#define N 500000
using namespace std;

typedef long long int ll;
vector<int> g[N+1];
set<int> adj[N+1];
int n, m, cnt, ss, p;
ll cw[N+1], w[N+1], dp[N+1], cidx[N+1];
int ind[N+1], num[N+1], low[N+1], chk[N+1];
stack<int> s;
vector<vector<int>> scc;

void dfs(int u) {
  chk[u] = 1;
  s.push(u);
  num[u] = ++cnt;
  low[u] = cnt;
  for (auto v : g[u]) {
    if (!num[v]) {
      dfs(v);
      low[u] = min(low[u], low[v]);
    } else if (chk[v]) {
      low[u] = min(low[u], num[v]);
    }
  }
  if (low[u] == num[u]) {
    vector<int> cc;
    while (!s.empty()) {
      int v = s.top(); s.pop();
      cc.push_back(v);
      chk[v] = 0;
      if (v == u) break;
    }
    for (auto v : cc) {
      cw[scc.size()] += w[v];
      cidx[v] = scc.size();
    }
    scc.push_back(cc);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>m;
  for (int i = 0; i < m; i++) {
    int u, v; cin>>u>>v;
    g[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) cin>>w[i];
  cin>>ss>>p;
  vector<int> rest(p);
  for (auto &pi : rest) cin>>pi;
  for (int i = 1; i <= n; i++) if (!num[i]) dfs(i);
  for (auto cc : scc)
    for (auto u : cc)
      for (auto v : g[u])
        if (cidx[u] != cidx[v] && adj[cidx[u]].count(cidx[v]) == 0) {
          adj[cidx[u]].insert(cidx[v]);
          ind[cidx[v]]++;
        }
  n = scc.size();
  queue<int> q;
  for (int i = 0; i < n; i++) {
    dp[i] = cw[i];
    if (ind[i] == 0) 
      q.push(i);
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto v : adj[u]) {
      dp[v] = max(dp[v], dp[u] + cw[v]);
      ind[v]--;
      if (ind[v] == 0) q.push(v);
    }
  }
  ll ans = 0;
  for (auto i : rest)
    ans = max(ans, dp[cidx[i]]);
  cout<<ans<<"\n";
}
