#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5;
int a[N+5], dp[N+5];

void f() {
  int n, k; 
  cin>>n>>k;
  a[0] = 0;
  for (int i = 1; i <= n; i++) cin>>a[i];
  for (int i = 0; i <= n; i++) dp[i] = 0;

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i]) {
      cnt = 0;
      continue;
    }

    cnt++;
    if (cnt >= k) {
      if (i-k-1 <= 0) dp[i] = max(1, dp[i-1]);
      else dp[i] = max(dp[i-k-1]+1, dp[i-1]);
    }
    else dp[i] = max(dp[i], dp[i-1]);
  }
  cout<<dp[n]<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) f();
}
