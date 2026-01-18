#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int n;
ll a[505][2], dp[505][505];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
  for (int i = 0; i < n-1; i++) dp[i][i+1] = a[i][0]*a[i][1]*a[i+1][1];
  for (int gap = 2; gap < n; gap++)
    for (int l = 0; l < n-gap; l++) {
      int r = l + gap;
      for (int m = l; m < r; m++) {
        if (dp[l][r] == 0) dp[l][r] = dp[l][m]+dp[m+1][r]+a[l][0]*a[m][1]*a[r][1];
        else dp[l][r] = min(dp[l][r], dp[l][m]+dp[m+1][r]+a[l][0]*a[m][1]*a[r][1]);
      }
    }
  cout << dp[0][n-1] << "\n";
}
