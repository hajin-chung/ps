#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
const int N = 2e5;
const int M = 2e5;
const int INF = 1e9;
const ll MOD = 998244353;

void dfs(int u, vector<ll> &a, vector<bool> &chk, vector<vector<int>> &g, vector<unordered_map<ll, ll>> &dp) {
  chk[u] = 1;
  for (auto v : g[u]) {
    if (a[v] <= a[u]) continue;
    if (!chk[v]) dfs(v, a, chk, g, dp);
    // cout<<"#"<<u<<" -> "<<v<<endl;
    dp[u][a[v]] = (dp[u][a[v]] + dp[v][a[u]+a[v]] + 1)%MOD;
  }
}

ll f() {
  int n, m; cin>>n>>m;
  vector<ll> a(n); for (auto &x: a) cin>>x;
  vector<vector<int>> g(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int u, v; cin>>u>>v; 
    u--; v--;
    g[u].push_back(v);
  }
  vector<bool> chk(n);
  vector<unordered_map<ll, ll>> dp(n);

  for (int i = 0; i < n; i++)
    if (chk[i] == 0)
      dfs(i, a, chk, g, dp);
  ll ans = 0;
  for (int u = 0; u < n; u++)
    for (auto v : g[u])
        ans = (ans + dp[v][a[v]+a[u]] + 1)%MOD;
  // for (int u = 0; u < n; u++) {
  //   cout<<u<<": ";
  //   for (auto [w, v] : dp[u])
  //     cout<<"("<<w<<", "<<v<<"), ";
  //   cout<<"\n";
  // }
  return ans;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t; cin>>t;
  while(t--) cout<<f()<<"\n";
}
