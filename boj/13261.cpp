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
  ll &ans = dp[t][m];
  for (int i = l; i < min(r, m); i++) {
    ll val = dp[t-1][i] + (sum[m]-sum[i])*(m-i);
    if (opt == -1 || ans > val) {
      opt = i;
      ans = val;
    }
  }
  f(t, s, m-1, l, opt+1);
  f(t, m+1, e, opt, r);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int l, g; cin>>l>>g;
  if (g >= l) g = l;
  for (int i = 1; i <= l; i++) {
    cin>>a[i];
    sum[i] = sum[i-1] + a[i];
  }
  for (int i = 1; i <= l; i++)
    dp[1][i] = sum[i]*i;
  for (int i = 2; i <= g; i++)
    f(i, 0, l, 0, l);
  cout<<dp[g][l]<<"\n";
}
