#include <bits/stdc++.h>
#define fi first
#define se second
#define N 100000
#define LOG_N 17
using namespace std;

typedef pair<int, int> pii;
int n;
int energy[N+5], ans[N+5];
pii dp[N+5][LOG_N+10];
bool chk[N+5];
vector<pii> adj[N+5];

void dfs(int curr) {
  for (auto [next, w] : adj[curr])
    if (!chk[next]) {
      dp[next][0] = {curr, w};
      chk[next] = 1;
      dfs(next);
    }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n; 
  for (int i = 1; i <= n; i++) cin >> energy[i];
  for (int i = 1; i <= n-1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  chk[0] = chk[1] = 1;
  dfs(1); 
  for (int i = 1; i <= LOG_N; i++)
    for (int j = 1; j <= n; j++) {
      dp[j][i] = {
        dp[dp[j][i-1].fi][i-1].fi,
        dp[dp[j][i-1].fi][i-1].se + dp[j][i-1].se
      };
    }

  for (int i = 1; i <= n; i++) {
    int e = energy[i], curr = i;
    for (int j = LOG_N; j >= 0; j--)
      if (dp[curr][j].se < e && dp[curr][j].fi != 0) {
        e -= dp[curr][j].se;
        curr = dp[curr][j].fi;
      }
    cout << curr << "\n";
  }
}
