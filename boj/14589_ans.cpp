#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
const int N = 150000;
int dp[N][20];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<int> idx(n);
  vector<pii> a(n);
  vector<pair<pii, int>> awi(n);
  for (int i = 0; i < n; i++) {
    int u, v; cin>>u>>v;
    awi[i] = {{u, v}, i};
  }
  sort(awi.begin(), awi.end());
  for (int i = 0; i < n; i++) idx[awi[i].se] = i;
  for (int i = 0; i < n; i++) a[i] = awi[i].fi;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 20; j++)
      dp[i][j] = j == 0 ? i : -1;
  set<pair<int, int>> ls;
  for (int i = 0; i < n; i++) {
    for (auto it = ls.begin(); it != ls.end();) {
      auto [se, idx] = *it;
      if (se < a[i].fi) {
        it = ls.erase(it);
        dp[idx][0] = i-1;
      } else break; 
    }
    ls.insert({a[i].se, i});
  }
  for (auto it = ls.begin(); it != ls.end();) {
    auto [se, idx] = *it;
    it = ls.erase(it);
    dp[idx][0] = n-1;
  }
  for (int j = 1; j < 20; j++)
    for (int i = 0; i < n; i++) 
      dp[i][j] = dp[dp[i][j-1]][j-1];
  for (int i = 0; i < n; i++) {
    cout<<i<<": ";
    for (int j = 0; j < 5; j++)
      cout<<dp[i][j]<<" ";
    cout<<"\n";
  }
  int q; cin>>q;
  while (q--) {
    int u, v; cin>>u>>v;
    u = idx[u-1]; v = idx[v-1];
    if (u > v) swap(u, v);
    int ans = 0;
    for (int i = 19; i >= 0; i--) {
      if (a[dp[u][i]].se >= a[v].se) continue;
      ans += 1<<i; 
      u = dp[u][i];
    }
    if (a[u].se < a[v].se && a[dp[u][0]].se >= a[v].se) {
      ans++;
      u = dp[u][0];
    }
    if (a[u].se < a[v].se) {
      cout<<"-1\n";
      continue;
    }
    cout<<u<<" "<<v<<"\n";
    cout<<ans<<"\n";
  }
}
