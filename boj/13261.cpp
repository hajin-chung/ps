#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll dp[8001][801];
ll a[801], sum[801];

// solve for dp[t][s...e] where l <= j <= r
void f(int t, int s, int e, int l, int r) {
  if (s > e) return;
  int m = (s+e)>>1;
  int opt = -1;
  ll c = 800*1e9;
  for (int i = l; i <= min(r, m); i++) {
    ll nc = (sum[m]-sum[i-1])*(m-i+1);
    if (dp[t-1][opt-1] + c > dp[t-1][i-1] + nc) {
      opt = i;
      c = nc;
    }
  }
  dp[t][m] = dp[t-1][opt-1] + c;
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
  for (int i = 1; i <= g; i++)
    for (int j = 1; j <= l; j++)
      dp[i][j] = 800 * 1e9;
  for (int i = 1; i <= l; i++)
    dp[1][i] = sum[i]*i;
  for (int i = 2; i <= g; i++)
    f(i, 1, l, 1, l);
  cout<<dp[g][l]<<"\n";
}
