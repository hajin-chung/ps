#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int dp[1<<16], n, a[16][16], p;

int rec(int mask) {
  if (dp[mask] != INF) return dp[mask];
  for (int i = 0; i < n; i++) 
    if (mask & (1<<i)) {
      int mn = INF;
      for (int j = 0; j < n; j++)
        if (i != j && mask & (1<<j))
          mn = min(mn, a[j][i]);
      dp[mask] = min(dp[mask], mn + rec(mask & (~(1<<i))));
    }
  return dp[mask];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin>>a[i][j];
  int mask = 0, mc = 0;
  for (int i = 0; i < n; i++) {
    char c;
    cin>>c;
    if (c == 'Y') {
      mask += (1<<i);
      mc++;
    }
  }
  cin>>p;
  if (p <= mc) {
    cout<< 0<<"\n";
    return 0;
  }
  for (int i = 0; i < (1<<16); i++) dp[i] = INF;
  dp[mask] = 0;
  int ans = INF;
  for (int i = 0; i < (1<<16); i++) {
    rec(i);
    int cnt = 0, t = i;
    while (t) {
      if (t & 1) cnt++;
      t >>= 1;
    }
    if (cnt == p) ans = min(ans, dp[i]);
  }
  cout << ans << "\n";
}
