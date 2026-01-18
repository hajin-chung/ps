#include <bits/stdc++.h>
#define INF 1000000000
#define N 500000
using namespace std;

typedef long long int ll;
int n, m, cnt;
stack<int> s;
vector<vector<int>> g, scc;
vector<set<int>> adj;
vector<int> num, low, cidx, ind;
vector<bool> chk;

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
    for (auto u : cc) cidx[u] = scc.size();
    scc.push_back(cc);
  }
}

void f() {
  cin>>n>>m;
  g.clear(); scc.clear(); adj.clear(); 
  num.clear(); low.clear(); cidx.clear(); ind.clear();
  chk.clear();
  g.resize(n); num.resize(n); low.resize(n); cidx.resize(n);
  chk.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v; cin>>u>>v;
    g[u].push_back(v);
  }
  cnt = 0;
  for (int i = 0; i < n; i++) if (!num[i]) dfs(i);
  adj.resize(scc.size());
  ind.resize(scc.size());
  for (auto cc : scc)
    for (auto u : cc)
      for (auto v : g[u])
        if (cidx[u] != cidx[v] && adj[cidx[u]].count(cidx[v]) == 0) {
          adj[cidx[u]].insert(cidx[v]);
          ind[cidx[v]]++;
        }
  int ans, cnt = 0;
  for (int i = 0; i < adj.size(); i++)
    if (ind[i] == 0) {
      ans = i;
      cnt++;
    }
  if (cnt != 1) cout<<"Confused\n";
  else {
    sort(scc[ans].begin(), scc[ans].end());
    for (auto u : scc[ans])
      cout<<u<<"\n";
  }
  cout<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) f();
}
