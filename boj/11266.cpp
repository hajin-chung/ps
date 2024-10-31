#include <bits/stdc++.h>
#define N 100005
using namespace std;

int n, m, t;
int order[N], par[N], low[N];
vector<vector<int>> adj;
vector<int> ans;

void dfs(int curr, bool root = false) {
  order[curr] = ++t;
  low[curr] = t;
  int cnt = 0;

  for (auto next : adj[curr]) {
    if (next == par[curr]) continue;
    if (order[next] == 0) {
      par[next] = curr;
      cnt++;
      dfs(next);
      if (root && cnt > 1) ans.push_back(curr);
      else if (!root && low[next] > order[curr]) ans.push_back(curr);
      low[curr] = min(low[curr], low[next]);
    }
    else low[curr] = min(low[curr], order[next]);
  }
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
  dfs(1, true);
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (auto ai : ans) printf("%d ", ai);
}
