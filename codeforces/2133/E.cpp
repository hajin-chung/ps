#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

vector<pair<int, int>> ans;

void dfs(int u, int p, vector<set<int>> &g, vector<bool> &chk) {
  ans.push_back({1, u});
  chk[u] = 1;
  for (auto v : g[u])
    if (v != p)
      dfs(v, u, g, chk);
}

void f() {
  ans.clear();
  int n; cin>>n;
  vector<set<int>> g(n+1);
  for (int i = 1; i < n; i++) {
    int u, v; cin>>u>>v;
    g[u].insert(v);
    g[v].insert(u);
  }
  set<pair<int, int>> st;
  for (int i = 1; i <= n; i++) st.insert({g[i].size(), i});
  while (!st.empty() && st.rbegin()->fi > 2) {
    auto it = st.rbegin();
    auto [cnt, u] = *it;
    ans.push_back({2, u});
    st.erase(*it);
    for (auto v : g[u]) {
      st.erase({g[v].size(), v});
      g[v].erase(u);
      st.insert({g[v].size(), v});
    }
    g[u].clear();
  }
  vector<bool> chk(n+1);
  for (int u = 1; u <= n; u++)
    if (!chk[u] && g[u].size() <= 1)
      dfs(u, -1, g, chk);
  cout<<ans.size()<<"\n";
  for (auto p : ans) cout<<p.fi<<" "<<p.se<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
