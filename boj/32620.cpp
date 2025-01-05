#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, int> pli;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, r; cin>>n>>m>>r; r--;
  vector<ll> a(n), b(n);
  for (auto &i : a) cin>>i;
  for (auto &i : b) cin>>i;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v; cin>>u>>v; u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<bool> chk(n);
  priority_queue<pli, vector<pli>, greater<pli>> pq;
  ll ans = 0;
  pq.push({a[r], r});
  while (!pq.empty()) {
    auto [aa, u] = pq.top(); pq.pop();
    if (aa > ans) continue; 
    chk[u] = 1;
    ans += b[u];
    for (auto v : g[u]) 
      if (!chk[v])
        pq.push({a[v], v});
  }
  cout<<ans<<"\n";
}
