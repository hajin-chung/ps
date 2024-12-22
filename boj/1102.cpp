#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int dp[1<<16], n, a[16][16], p, mask;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin>>a[i][j];
  for (int i = 0; i < n; i++) {
    char x; cin>>x;
    if (x == 'Y') mask += (1<<i);
  }
  cin>>p;
  if (p == 0) {
    cout<<"-1\n"; return 0;
  } else if (__builtin_popcount(mask) >= p) {
    cout<<0<<"\n"; return 0;
  }
  for (int i = 0; i < (1<<n); i++) dp[i] = INF;
  dp[mask] = 0;
  int ans = INF;
  for (int i = mask; i < (1<<n); i++)
    for (int j = 0; j < n; j++) 
      if ((i & (1<<j)) == 0) {
        int q = i | (1<<j), w = INF;
        for (int k = 0; k < n; k++) 
          if ((i & (1<<k)) != 0 && a[k][j] < w)
            w = a[k][j];
        if (dp[q] > dp[i] + w) {
          dp[q] = dp[i] + w;
          if (__builtin_popcount(q) >= p && ans > dp[q]) {
            ans = dp[q];
          }
        }
      }
  cout<<ans<<"\n";
}
