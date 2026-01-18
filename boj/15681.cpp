#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> cnt, chk;

int dfs(int curr) {
  chk[curr] = 1;
  cnt[curr] = 1;
  for (auto next : adj[curr])
    if (!chk[next]) 
      cnt[curr] += dfs(next);
  return cnt[curr];
}

int main() {
  int n, r, q;

  scanf("%d %d %d", &n, &r, &q);
  adj.resize(n+1);
  cnt.resize(n+1);
  chk.resize(n+1);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(r);
  for (int i = 0; i < q; i++) {
    int u;
    scanf("%d", &u);
    printf("%d\n", cnt[u]);
  }
}
