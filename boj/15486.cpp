#include <bits/stdc++.h>
#define N 1500000
using namespace std;

int n, dp[N+2];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  for (int i = 1; i <= n; i++) {
    int t, c;  
    cin>>t>>c;
    dp[i] = max(dp[i], dp[i-1]);
    if (i+t <= n+1) dp[i+t] = max(dp[i+t], dp[i]+c);
  }
  cout << max(dp[n], dp[n+1]) << "\n";
}
