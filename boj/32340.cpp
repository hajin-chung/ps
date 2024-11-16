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
  if (m > n) {
    cout<<0<<"\n";
    return 0;
  }

  ll ans = 0, sum = 0;
  for (int i = 1; i <= n; i++)
    if (!chk[i]) {
      chk[i] = true;
      ll cnt = dfs(i);
      if (cnt == n) {
        cout<<1<<"\n";
        return 0;
      } else {
        if (sum != 0) ans += sum * cnt;
        sum += cnt;
        if (ans > k) {
          cout<<"-1"<<"\n";
          return 0;
        }
      }
    }
  cout<<ans<<"\n";
}
