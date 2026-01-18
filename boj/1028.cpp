#include <bits/stdc++.h>
using namespace std;

int a[755][755], l[755][755], r[755][755];

bool possible(int yy, int xx, int k) {
  int ly, lx, ry, rx;
  ly = yy - k + 1;
  ry = yy - k + 1;
  lx = xx - k + 1;
  rx = xx + k - 1;
  if (r[ly][lx] >= k && l[ry][rx] >= k) return true;
  return false;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin>>n>>m;
  for (int i = 1; i <= n; i++) {
    string s; cin>>s;
    for (int j = 1; j <= m; j++)
      a[i][j] = s[j-1] == '1';
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j]) {
        l[i][j] = l[i-1][j-1] + 1;
        r[i][j] = r[i-1][j+1] + 1;
      }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j])
        for (int k = 1; k <= min(l[i][j], r[i][j]); k++)
          if (possible(i, j, k))
            ans = max(ans, k);
  cout<<ans<<"\n";
}
