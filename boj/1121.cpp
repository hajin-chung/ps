#include <bits/stdc++.h>
#define MAX 50000
using namespace std;

typedef long long int ll;
ll dp[10][MAX+5];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<ll> a(n), sum(n);
  for (int i = 0; i < n; i++) cin>>a[i]; 
  int k; cin>>k;
  sort(a.begin(), a.end());
  sum[0] = a[0];
  for (int i = 1; i < n; i++) sum[i] = a[i] + sum[i-1];
  dp[0][0] = 1;
  ll cnt = 0;
  for (int i = 0; i < n; i++) {
    if (i + 1 >= k)
      for (int j = a[i]+1; j <= MAX+1; j++)
        cnt += dp[k-1][j];
    for (int kk = k-1; kk > 0; kk--)
      for (int j = sum[i]; j >= a[i]; j--) {
        int u = min(j, MAX+1), v = min(j-(int)a[i], MAX+1);
        dp[kk][u] += dp[kk-1][v];
      }
  }
  cout<<cnt<<"\n";
}
