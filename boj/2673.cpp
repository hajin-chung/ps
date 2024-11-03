#include <bits/stdc++.h>
using namespace std;

int n, a[101][101], dp[101][101];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 0, s, e; i < n; i++) {
    cin >> s >> e;
    a[s][e] = a[e][s] = 1;
  }
  
  for (int i = 1; i <= 100; i++)
    for (int j = i; j >= 1; j--)
      for (int k = j; k < i; k++)
        dp[j][i] = max(dp[j][i], dp[j][k]+dp[k][i]+a[j][i]);
  cout << dp[1][100] << "\n";
}
