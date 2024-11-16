#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int n, m;
ll k;
vector<int> chk, adj[101010];

ll dfs(int u) {
  ll ret = 1;
  for (auto v : adj[u])
    if (!chk[v]) {
      chk[v] = 1;
      ret += dfs(v);
    }
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>m>>k; chk.resize(n+1, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++)
    if (!chk[i]) {
      chk[i] = true;
      int cnt = dfs(i);
      if (ans < 0) continue;
      if (cnt == n) ans = 1;
      else {
        if (ans == 0) ans = cnt;
        else ans *= cnt;
        if (ans > k) ans = -1;
      }
    }
  cout<<ans<<"\n";
}
