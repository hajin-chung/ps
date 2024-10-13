#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n, m, md;
vector<vector<pii>> a, dp;
vector<int> depth;

void dfs(int curr) {
  int max_level = (int)floor(log2(depth[curr]));
  dp.resize(max_level);

  for (int i = 1; i < max_level; i++) {
    int p = dp[curr][i-1].first;
    dp[curr][i] = {dp[p][i-1].first, dp[curr][i-1].second + dp[p][i-1].second};
  }

  for (auto {next, w} : a[curr]) {
    depth[next] = depth[curr] + 1;
    dp[next][0] = {curr, w};
    dfs(next);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int i;
  int x, y, z;

  cin >> n;
  md = (int)floor(log2(n));
  dp.resize(n+1);
  depth.resize(n+1);
  a.resize(n+1);
  for (i = 0; i < n; i++) {
    cin >> x >> y >> z; 
    a[x].push_back({y, z});
  }

  depth[1] = 1;
  dfs(1);
  for (int i = 1; i <= n; i++) {

  }
}
