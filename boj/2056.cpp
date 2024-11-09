#include <bits/stdc++.h>
using namespace std;

int n, dp[10005];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int t, m, mt = 0, j;
    cin>>t>>m;
    for (int k = 0; k < m; k++) {
      cin>>j;
      mt = max(mt, dp[j]);
    }
    dp[i] = mt+t;
    ans = max(ans, dp[i]);
  }
  cout << ans << "\n";
}
