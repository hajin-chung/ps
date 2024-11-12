#include <bits/stdc++.h>
#define N 200
using namespace std;

typedef long long int ll;
ll dp[N+1][N+1][N+1];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin>>t;
  dp[1][1][1] = 1;
  for (int i = 2; i <= N; i++)
    for (int j = 1; j <= i; j++)
      for (int k = 1; k <= i; k++)
        dp[i][j][k] += dp[i-1][j-1][k] + dp[i-1][j][k-1] + (i-2)*dp[i-1][j][k];
  while (t--) {
    int n, l, r;
    cin>>n>>l>>r;
    cout<<dp[n][l][r]<<"\n";
  }

}
