#include <bits/stdc++.h>
using namespace std;

int n, dp[10005];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  for (int i = 1; i <= n; i++) {
    int t, m, mt = 0, j;
    cin>>t>>m;
    while (m--) {
      cin>>j;
      mt = max(mt, dp[j]);
    }
    dp[i] = mt+t;
  }
  cout << dp[n] << "\n";
}
