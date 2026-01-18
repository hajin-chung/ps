// anc = lca(capital, curr)
// ancnext = child of anc on the route to capital
// if depth[anc] < depth[curr] => childcnt[curr]
// else depth[anc] == depth[curr] => n - childcnt[ancnext] 

#include <bits/stdc++.h>
#define N 100000
#define LOG_N 20
#define pb push_back
using namespace std;

typedef pair<int, int> pii;
int dp[N+1][LOG_N];
vector<vector<int>> adj; 
vector<int> cnt, depth;
vector<bool> chk;

int dfs(int curr, int lev) {
  chk[curr] = true;
  depth[curr] = lev;
  cnt[curr] = 1;
  for (auto next : adj[curr])
    if (!chk[next]) {
      dp[next][0] = curr;
      cnt[curr] += dfs(next, lev+1);
    }
  return cnt[curr];
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  for (int i = LOG_N-1; i >= 0; i--)
    if (depth[dp[u][i]] >= depth[v])
      u = dp[u][i];
  if (u == v) return u;
  for (int i = LOG_N-1; i >= 0; i--)
    if (dp[u][i] != dp[v][i]) {
      u = dp[u][i];
      v = dp[v][i];
    }
  return dp[u][0];
}

void solve(int tc) {
  int n, q, r;
  cin>>n>>q>>r;
  adj.clear(); adj.resize(n+1);
  chk.clear(); chk.resize(n+1);
  cnt.clear(); cnt.resize(n+1);
  depth.clear(); depth.resize(n+1);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < LOG_N; j++)
      dp[i][j] = 0;
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  depth[0] = -1;
  dfs(r, 0);
  for (int i = 1; i < LOG_N; i++)
    for (int j = 1; j <= n; j++)
      dp[j][i] = dp[dp[j][i-1]][i-1];

  /*for (int i = 1; i <= n; i++) {*/
  /*  cout << i << ": ";*/
  /*  for (int j = 0; j < 7; j++)*/
  /*    cout << dp[i][j] << " ";*/
  /*  cout << endl;*/
  /*}*/
  /*cout << "counts:" <<endl;*/
  /*for (int i = 1; i <= n; i++)*/
  /*  cout << cnt[i] << " ";*/
  /*cout << endl;*/

  cout<<"Case #"<<tc<<":\n";
  while (q--) {
    int s, u;
    cin>>s>>u;
    if (s == 0) r = u;
    else {
      int anc = lca(r, u);
      if (r == u) cout<<n<<"\n";
      else if (anc == u) {
        int ancnext = r;
        for (int i = LOG_N-1; i >= 0; i--)
          if (depth[dp[ancnext][i]] > depth[anc])
            ancnext = dp[ancnext][i];
        cout<<n-cnt[ancnext]<<"\n";
      }
      else cout<<cnt[u]<<"\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin>>t;
  for (int i = 1; i <= t; i++) solve(i);
}
