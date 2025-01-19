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
  vector<pii> a(n);
  for (auto &[x, y] : a) cin>>x>>y;
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 20; j++)
      dp[i][j] = {-1, -1};
  set<pii> ss;
  for (int i = 0; i < n; i++) {
    for (auto [x, idx] : ss) 
      if (a[idx].se < a[i].fi)
        ss.erase({x, idx});
    if (!ss.empty()) {
      auto [se, j] = *ss.begin();
      dp[i][0].fi = j;
      if (dp[j][0].se == -1 || a[dp[j][0].se].se < a[i].se)
        dp[j][0].se = i;
    }
    ss.insert({a[i].fi, i});
  }
  for (int i = 0; i < n; i++) {
    cout<<i<<": ";
    for (int j = 0; j < 3; j++)
      cout<<"("<<dp[i][j].fi<<","<<dp[i][j].se<<") "<<" ";
    cout<<"\n";
  }
}
