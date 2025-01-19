#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
const int N = 150000;
pii dp[N][20];

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
      dp[i][j] = j == 0 ? make_pair(i, i) : make_pair(-1, -1);
  set<pii> ss, ls;
  for (int i = 0; i < n; i++) {
    for (auto it = ls.begin(); it != ls.end();) {
      auto [se, idx] = *it;
      if (se < a[i].fi) {
        it = ls.erase(it);
        dp[idx][0].se = i-1;
        ss.erase({a[idx].fi, idx});
      } else break; 
    }
    if (!ss.empty()) dp[i][0].fi = ss.begin()->se;
    ss.insert({a[i].fi, i});
    ls.insert({a[i].se, i});
  }
  for (int j = 1; j < 20; j++)
    for (int i = 0; i < n; i++) {
      dp[i][j].fi = dp[dp[i][j-1].fi][j-1].fi;
      dp[i][j].se = dp[dp[i][j-1].se][j-1].se;
    }
  /*for (int i = 0; i < n; i++) {*/
  /*  cout<<i<<": ";*/
  /*  for (int j = 0; j < 3; j++)*/
  /*    cout<<"("<<dp[i][j].fi<<","<<dp[i][j].se<<") "<<" ";*/
  /*  cout<<"\n";*/
  /*}*/
  int q; cin>>q;
  while (q--) {
    int u, v; cin>>u>>v; u--; v--;
    u = idx[u]; v = idx[v];
    if (a[u] > a[v]) swap(u, v);
    int ans = 0;
    for (int i = 19; i >= 0; i--) {
      if (a[dp[u][i].fi].fi <= a[v].fi && a[v].se <= a[dp[u][i].se].se)
        continue;
      ans += 1<<i;
      u = dp[u][i].se;
    }
    if (a[dp[u][0].fi].fi <= a[v].fi && a[v].se <= a[dp[u][0].se].se) {
      cout<<ans+1<<"\n";
    } else {
      cout<<"-1\n";
    }
  }
}
