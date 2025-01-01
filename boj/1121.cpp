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
    if (i >= k - 1)
      for (int j = a[i]+1; j <= MAX+1; j++)
        cnt += dp[k-1][j];
    for (int kk = k-1; kk > 0; kk--) {
      for (int j = 0; j <= MAX; j++) 
        if (dp[kk-1][j] > 0) {
          if (j + a[i] > MAX) dp[kk][MAX+1] += dp[kk-1][j];
          else dp[kk][j+a[i]] += dp[kk-1][j];
        }
    }
    /*for (int kk = 1; kk <= k-1; kk++) {*/
    /*  for (int j = 0; j <= MAX+1; j++)*/
    /*    if (dp[kk][j])*/
    /*    cout<<dp[kk][j]<<","<<j<<" ";*/
    /*  cout<<"\n";*/
    /*}*/
    /*cout<<"\n";*/
  }
  cout<<cnt<<"\n";
}
