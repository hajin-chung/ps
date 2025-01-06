#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int n, m;
set<int> a[20][26];
int dp[20][20];

int f(int u, int v) {
  cout<<u<<" "<<v<<"\n";
  if (dp[u][v] != INF) return dp[u][v];
  if (u == v) return dp[u][v] = 0;
  bool flag = 0;
  for (int i = 0; i < 26; i++)
    flag |= a[u][i].count(v);
  if (flag) return dp[u][v] = 1;
  int ret = INF;
  for (int i = 0; i < 26; i++)
    for (auto nu : a[u][i])
      for (auto nv : a[v][i])
        ret = min(ret, f(nu, nv)+2);
  return dp[u][v] = ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>m;
  for (int i = 0; i < m; i++) {
    int u, v; char c; cin>>u>>v>>c;
    a[u][c-'a'].insert(v);
    a[v][c-'a'].insert(u);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      dp[i][j] = INF;
  int ans = f(0, 1);
  if (ans == INF) cout<<"-1\n";
  else cout<<ans<<"\n";
}
