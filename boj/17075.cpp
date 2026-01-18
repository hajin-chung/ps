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
  vector<bool> chk(k), tchk(k);
  vector<pii> coord(k);
  vector<int> path(k);
  chk[sum] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j] == -1) {
        tchk = chk;
        for (int kk = 0; kk < k; kk++) {
          int nkk = (kk+cnt[i][j])%k;
          if (chk[kk] && !chk[nkk]) {
            tchk[nkk] = true;
            coord[nkk] = {i, j};
            path[nkk] = kk;
          }
        }
        chk = tchk;
      }
  if (!chk[0]) cout<<"-1\n";
  else {
    set<pii> ans;
    int kk = 0;
    while (kk != sum) {
      ans.insert(coord[kk]);
      kk = path[kk];
    }
    cout<<"1\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 1 || a[i][j] == 0) cout<<a[i][j]<<" ";
        else {
          if (ans.count({i, j})) cout<<"1 ";
          else cout<<"0 ";
        }
      }
      cout<<"\n";
    }
  }
}
