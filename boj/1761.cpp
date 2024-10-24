#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n, m, md, ml, root;
vector<vector<pii>> adj, dp, tree;
vector<int> depth, isChild, vs;

void find_root(int curr) {
  bool flag = false;
  for (auto [next, w] : adj[curr]) 
    if (vs[next] == 0) {
      vs[next] = 1;
      find_root(next);
      flag = true;
      vs[next] = 0;
    }
  if (flag == false) root = curr;
}

void make_tree(int curr, int lev) {
  depth[curr] = lev;
  md = max(md, lev);
  for (auto [next, w] : adj[curr])
    if (vs[next] == 0) {
      vs[next] = 1;
      tree[curr].push_back({next, w});
      make_tree(next, lev+1);
      vs[next] = 0;
    }
}

void dfs(int curr) {
  if (depth[curr] > 0) {
    int max_level = (int)floor(log2(depth[curr]));
    for (int i = 1; i <= max_level; i++) {
      int p = dp[curr][i-1].first;
      dp[curr][i] = {dp[p][i-1].first, dp[curr][i-1].second + dp[p][i-1].second};
    }
  }

  for (auto [next, w] : tree[curr]) {
    int max_level = (int)floor(log2(depth[next]));
    dp[next][0] = {curr, w};
    dfs(next);
  }
}

int lca(int x, int y) {
  int ret = 0;
  if (depth[x] != depth[y]) {
    if (depth[x] > depth[y]) swap(x, y);
    for (int i = ml; i >= 0; i--)
      if (depth[x] <= depth[dp[y][i].first]) {
        ret += dp[y][i].second;
        y = dp[y][i].first;
      }
  }
  if (x != y) {
    for (int i = ml; i >= 0; i--) {
      if (dp[x][i].first != dp[y][i].first) {
        ret += dp[x][i].second + dp[y][i].second;
        x = dp[x][i].first;
        y = dp[y][i].first;
      }
    }
    ret += dp[x][0].second + dp[y][0].second;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int i;
  int x, y, z;

  cin >> n;
  depth.resize(n+1);
  adj.resize(n+1);
  vs.resize(n+1);
  tree.resize(n+1);
  for (i = 0; i < n-1; i++) {
    cin >> x >> y >> z; 
    adj[x].push_back({y, z});
    adj[y].push_back({x, z});
  }

  depth[0] = -1;
  vs[1] = 1;
  find_root(1);
  vs[1] = 0;
  vs[root] = 1;
  make_tree(root, 0);

  ml = (int)floor(log2(md));
  dp.resize(n+1, vector<pii>(ml+1));
  dfs(root);

  cin >> m;
  while (m--) {
    cin >> x >> y;
    cout << lca(x, y) << "\n";
  }
}
