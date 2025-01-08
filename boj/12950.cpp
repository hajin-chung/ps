#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin>>n>>m;
  vector<int> g[20][26];
  for (int i = 0; i < m; i++) {
    int u, v; char c; cin>>u>>v>>c;
    g[u][c-'a'].pb(v);
    g[v][c-'a'].pb(u);
  }
  bool dp[105][20][20];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) dp[1][i][i] = 1;
  for (int i = 0; i < n; i++)
    for (int c = 0; c < 26; c++)
      for (auto j : g[i][c])
        dp[2][i][j] = 1;
  for (int l = 3; l <= 100; l++) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        for (int c = 0; c < 26; c++)
          for (auto u : g[i][c])
            for (auto v : g[j][c])
              if (dp[l-2][u][v]) {
                dp[l][i][j] = 1;
              }
        if (dp[l][0][1]) {
          cout<<l-1<<"\n";
          return 0;
        }
      }
  }
  cout<<"-1\n";
}
