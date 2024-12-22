#include <bits/stdc++.h>
#define N 1000
using namespace std;

int num[N+1], low[N+1], chk[N+1], cidx[N+1], ind[N+1], oud[N+1];
int n, k, cnt;
vector<int> g[N+1];
set<int> adj[N+1], radj[N+1];
stack<int> s;
vector<vector<int>> scc;
set<int> dp[N+1];

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
    for (auto v : cc) cidx[v] = scc.size();
    scc.push_back(cc);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>k; 
  for (int i = 1; i <= n; i++) {
    int x; cin>>x;
    if (i == x) continue;
    g[i].push_back(x);
  }
  for (int i = 1; i <= n; i++) if (!num[i]) dfs(i);
  for (auto cc : scc)
    for (auto u : cc)
      for (auto v : g[u])
        if (cidx[u] != cidx[v] && adj[cidx[u]].count(cidx[v]) == 0) {
          adj[cidx[u]].insert(cidx[v]);
          radj[cidx[v]].insert(cidx[u]);
          oud[cidx[u]]++;
          ind[cidx[v]]++;
        }
  int m = scc.size();
  for (int i = 0; i < m; i++) chk[i] = 0;
  queue<int> q;
  for (int i = 0; i < m; i++)
    if (ind[i] == 0)
      q.push(i);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    dp[u].insert(scc[u].size());
    for (auto v : radj[u]) {
      auto dpu = dp[u];
      for (auto vs : dp[v])
        for (auto us : dpu) {
          dp[u].insert(vs + us);
        }
    }
    for (auto v : adj[u]) {
      ind[v]--;
      if (ind[v] == 0) q.push(v);
    }
  }
  set<int> ans;
  ans.insert(0);
  for (int i = 0; i < m; i++)
    if (oud[i] == 0) {
      set<int> aa = ans;
      dp[i].insert(0);
      for (auto ds : dp[i])
        for (auto as : aa)
          ans.insert(as + ds);
    }
  auto iter = --ans.upper_bound(k);
  cout<<*iter<<"\n";
}
