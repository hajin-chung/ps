#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int N = 2000;
ll INF;
int n;
ll a[N+1], sum[N+1];

bool solve1(ll bit, int mx) {
  ll dp[N+1];
  for (int i = 1; i <= n; i++) dp[i] = INF;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < i; j++) 
      if (((sum[i]-sum[j])|bit) == bit)
        dp[i] = min(dp[i], dp[j]+1);
  return dp[n] <= mx;
}

void solve1(int mx) {
  ll bit = (1LL<<41)-1;
  for (int i = 40; i >= 0; i--) {
    bit -= (1LL<<i);
    if (!solve1(bit, mx)) bit += (1LL<<i);
  }
  cout<<bit<<"\n";
}

bool solve2(ll bit, int l, int r) {
  // dp[i][j] : can seperate 1~i in j groups with value in bit
  // dp[i][j] = dp[k][j-1] && sum[i]-sum[k] | bit == bit
  bool dp[105][105]; 
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= min(i, r); j++)
      for (int k = 0; k < i; k++)
        if (dp[k][j-1] && (sum[i]-sum[k] | bit) == bit) {
          dp[i][j] = 1;
          if (i == n && j >= l) return true;
        }
  return false;
}

void solve2(int l, int r) {
  ll bit = (1LL<<41)-1;
  for (int i = 40; i >= 0; i--) {
    bit -= (1LL<<i);
    if (!solve2(bit, l, r)) bit += (1LL<<i);
  }
  cout<<bit<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int l, r; cin>>n>>l>>r;
  for (int i = 1; i <= n; i++) cin>>a[i];
  for (int i = 1; i <= n; i++) sum[i] = a[i] + sum[i-1];
  INF = sum[n]*2;
  if (l == 1) solve1(r);
  else solve2(l, r);
}
