#include <bits/stdc++.h>
#define N 100005
using namespace std;

int n, m, t, order[N];
bool cut[N];
vector<vector<int>> adj;
vector<int> ans;

int dfs(int curr, bool root = false) {
  order[curr] = ++t;
  int ret = order[curr];
  int cnt = 0;
  for (auto next : adj[curr]) {
    if (order[next] == 0) {
      cnt++;
      int df = dfs(next);
      if (!root && df >= order[curr]) cut[curr] = true;
      ret = min(ret, df);
    }
    else ret = min(ret, order[next]);
  }
  if (root && cnt > 1) cut[curr] = true;
  return ret;
}

int main() {
  scanf("%d%d", &n, &m);
  adj.resize(n+1);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++)
    if (!order[i])
      dfs(i, true);
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (cut[i])
      cnt++;
  printf("%d\n", cnt);
  for (int i = 1; i <= n; i++)
    if (cut[i])
      printf("%d ", i);
}
