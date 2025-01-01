#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll dp[21][21];

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

ll fact(int a) {
  ll ret = 1;
  for (int i = 1; i <= a; i++) ret *= (ll)i;
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k; cin>>n>>k; 
  dp[1][1] = 1;
  for (int i = 2; i <= 20; i++)
    for (int j = 1; j <= i; j++)
      dp[i][j] = dp[i-1][j-1] + (i-1)*dp[i-1][j];
  ll sum = 0;
  for (int i = 1; i <= k; i++) sum += dp[n][i];
  ll fn = fact(n);
  ll g = gcd(sum, fn);
  cout<<sum/g<<"/"<<fn<<"\n";
}
