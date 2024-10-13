#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n, m, md, ml;
vector<vector<pii>> a, dp;
vector<int> depth, isChild;

void dfs(int curr) {
  md = max(md, depth[curr]);
  if (depth[curr] > 0) {
    int max_level = (int)floor(log2(depth[curr]));
    for (int i = 1; i <= max_level; i++) {
      int p = dp[curr][i-1].first;
      dp[curr][i] = {dp[p][i-1].first, dp[curr][i-1].second + dp[p][i-1].second};
    }
  }

  for (auto [next, w] : a[curr]) {
    depth[next] = depth[curr] + 1;

    int max_level = (int)floor(log2(depth[next]));
    dp[next].resize(max_level + 1);
    dp[next][0] = {curr, w};
    dfs(next);
  }
}

int lca(int x, int y) {
  int ret = 0;
  if (depth[x] != depth[y]) {
    if (depth[x] > depth[y]) swap(x, y);
    for (int i = dp[y].size()-1; i >= 0; i--)
      if (depth[x] <= depth[dp[y][i].first]) {
        ret += dp[y][i].second;
        y = dp[y][i].first;
      }
  }
  if (x != y) {
    for (int i = dp[x].size()-1; i >= 0; i--) {
      if (dp[x][i] != dp[y][i]) {
        x = dp[x][i].first;
        y = dp[y][i].first;
      }
      ret += dp[x][i].second + dp[y][i].second;
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int i;
  int x, y, z;
  int root;

  cin >> n;
  dp.resize(n+1);
  depth.resize(n+1);
  a.resize(n+1);
  isChild.resize(n+1, 0);
  for (i = 0; i < n-1; i++) {
    cin >> x >> y >> z; 
    isChild[y] = 1;
    a[x].push_back({y, z});
  }

  for (i = 1; i <= n; i++) if (!isChild[i]) root = i;

  dfs(root);
  // for (int i = 1; i <= n; i++) {
  //   cout << i << ": ";
  //   for (auto [p, w] : dp[i])
  //     cout << "{" << p << ", " << w << "}, ";
  //   cout << "\n";
  // }
  // cout << endl;

  cin >> m;
  while (m--) {
    cin >> x >> y;
    cout << lca(x, y) << "\n";
  }
}
