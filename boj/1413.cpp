#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll dp[21][21];

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k; cin>>n>>k; 
  dp[1][1] = 1;
  for (int i = 2; i <= 20; i++)
    for (int j = 1; j <= i; j++)
      dp[i][j] = dp[i-1][j-1] + (i-1)*dp[i-1][j];
  for (int i = 1; i <= n; i++) dp[n][i] += dp[n][i-1];
  ll g = gcd(dp[n][k], dp[n][n]);
  cout<<dp[n][k]/g<<"/"<<dp[n][n]/g<<"\n";
}
