#include <bits/stdc++.h>
using namespace std;

int n, dp[100005][2];

int main() {
  cin>>n;
  int ans = -1000;
  dp[0][0] = dp[0][1] = -1000;
  for (int i = 1; i <= n; i++) {
    int x;
    cin>>x;
    dp[i][0] = max(dp[i-1][0], 0)+x;
    dp[i][1] = max(dp[i-1][1]+x, dp[i-1][0]); 
    ans = max(ans, max(dp[i][0], dp[i][1]));
  }
  cout << ans << "\n";
}
