#include <bits/stdc++.h>
#define INF 1000000000
#define N 100
#define K 10000
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

void solve() {
  int n, m, k; cin>>n>>k>>m;
  vector<vector<ppi>> a(n+1);
  for (int i = 0; i < m; i++) {
    int u, v, c, d; cin>>u>>v>>c>>d; 
    a[u].push_back({{d, c}, v});
  }
  int dp[N+1][K+1];
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= k; j++)
      dp[i][j] = INF;
  dp[1][0] = 0;
  queue<ppi> pq;
  pq.push({{0, 0}, 1});
  while (!pq.empty()) {
    auto [dc, u] = pq.front(); pq.pop();
    auto [ud, uc] = dc;
    if (dp[u][uc] < ud) continue;
    for (auto [dc, v] : a[u]) {
      auto [vd, vc] = dc;
      if (uc+vc <= k && dp[v][uc+vc] > ud + vd) {
        dp[v][uc+vc] = ud + vd;
        pq.push({{ud+vd, uc+vc}, v});
      }
    }
  }
  int ans = INF;
  for (int i = 0; i <= k; i++)
    ans = min(ans, dp[n][i]);
  if (ans == INF) cout<<"Poor KCM\n";
  else cout<<ans<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) solve();
}
