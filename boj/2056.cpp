#include <bits/stdc++.h>
using namespace std;

int n, dp[10005];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  for (int i = 1; i <= n; i++) {
    int t, m, mt = 0, k;
    cin>>t>>m;
    for (int j = 0; j < m; j++) {
      cin>>k;
      mt = max(mt, dp[k]);
    }
    dp[i] = mt+t;
  }
  cout << dp[n] << "\n";
}
