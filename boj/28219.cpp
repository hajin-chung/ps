#include <bits/stdc++.h>
using namespace std;

const int N = 200000;
vector<int> g[N];
int ans = 0;
int n, k; 

int dfs(int u, int p) {
  multiset<int> h;
  for (auto v : g[u])
    if (v != p)
      h.insert(dfs(v, u));
  if (h.size() == 0) {
    return 1;
  } else if (h.size() == 1 && *h.rbegin() == k) {
    ans++;
    return 0;
  } else if (h.size() >= 2) {
    auto h1 = prev(h.end());
    auto h2 = prev(h1);
    if (*h1 + *h2 >= k) {
      ans++;
      return 0;
    }
  }
  return *h.rbegin()+1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>k;
  for (int i = 1; i < n; i++) {
    int u, v; cin>>u>>v; u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, -1);
  cout<<ans<<"\n";
}
