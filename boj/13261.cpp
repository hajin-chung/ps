#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll dp[8001][801];
ll a[801], sum[801];
const ll INF = LLONG_MAX/2;

// solve for dp[t][s...e] where l <= j <= r
void f(int t, int s, int e, int l, int r) {
  if (s > e) return;
  int m = (s+e)>>1;
  int opt = l;
  ll c = dp[t-1][opt-1] + (sum[m]-sum[l-1])*(m-l+1);
  for (int i = l+1; i <= min(r, m); i++) {
    ll nc = dp[t-1][i-1] + (sum[m]-sum[i-1])*(m-i+1);
    if (c > nc) {
      opt = i;
      c = nc;
    }
  }
  dp[t][m] = c;
  f(t, s, m-1, l, opt);
  f(t, m+1, e, opt, r);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int l, g; cin>>l>>g;
  for (int i = 1; i <= l; i++) {
    cin>>a[i];
    sum[i] = sum[i-1] + a[i];
  }
  if (g >= l) {
    cout<<sum[l]<<"\n";
    return 0;
  }
  for (int i = 1; i <= g; i++)
    for (int j = 1; j <= l; j++)
      dp[i][j] = INF;
  for (int i = 1; i <= l; i++)
    dp[1][i] = sum[i]*i;
  for (int i = 2; i <= g; i++)
    f(i, 1, l, 1, l);
  ll ans = INF;
  for (int i = 1; i <= g; i++)
    ans = min(ans, dp[i][l]);
  cout<<ans<<"\n";
}
