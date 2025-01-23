#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int N = 2000;
const ll INF = LLONG_MAX/2;
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

ll dp[N+1][N+1]; 
void solve2(int l, int r) {
  // dp[i][j] = min value of j'th element ending i'th bundle
  // dp[i][j] = min(dp[i-1][k] | sum[j]-sum[k]) (i-1 <= k < j, j <= i)
  for (int i = 1; i <= r; i++)
    for (int j = 1; j <= n; j++)
      dp[i][j] = INF;
  for (int i = 1; i <= r; i++)
    for (int j = i; j <= n; j++)
      for (int k = i-1; k < j; k++)
        dp[i][j] = min(dp[i][j], dp[i-1][k]|(sum[j]-sum[k]));
  ll ans = INF;
  for (int i = l; i <= r; i++)
    ans = min(ans, dp[i][n]);
  cout<<ans<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int l, r; cin>>n>>l>>r;
  for (int i = 1; i <= n; i++) cin>>a[i];
  for (int i = 1; i <= n; i++) sum[i] = a[i] + sum[i-1];
  if (l == 1) solve1(r);
  else solve2(l, r);
}
