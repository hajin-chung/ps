#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k; cin>>n>>m>>k;
  int a[50][50];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin>>a[i][j];
  int cnt[50][50], sum = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int ii = min(i+1, n-i), jj = min(j+1, m-j);
      cnt[i][j] = (ii*(n+2)-ii*(ii+1))*(jj*(m+2)-jj*(jj+1));
      if (a[i][j] == 1) sum = (sum + cnt[i][j])%k;
    }
  vector<pair<bool, set<pii>>> dp(k), ndp(k);
  dp[sum].first = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j] == -1) {
        ndp = dp;
        for (int kk = 0; kk < k; kk++) {
          int nkk = (kk+cnt[i][j])%k;
          if (ndp[kk].first && !ndp[nkk].first) {
            ndp[nkk].first = true;
            ndp[nkk].second = ndp[kk].second;
            ndp[nkk].second.insert({i, j});
          }
        }
        dp = ndp;
      }
  if (!dp[0].first) cout<<"-1\n";
  else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 1 || a[i][j] == 0) cout<<a[i][j]<<" ";
        else {
          if (dp[0].second.count({i, j})) cout<<"1 ";
          else cout<<"0 ";
        }
      }
      cout<<"\n";
    }
  }
}
