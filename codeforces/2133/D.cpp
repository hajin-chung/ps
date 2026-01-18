#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

typedef int64_t ll;

void f() {
  int n; cin>>n; 
  vector<ll> a(n+1);
  for (int i = 1; i <= n; i++) cin>>a[i];
  vector<ll> dp(n+1);
  dp[1] = a[1];
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i-1]+a[i]-1;
    dp[i] = min(dp[i], dp[i-2]+a[i-1]+max((ll)0, a[i]-(i-1)));
  }
  cout<<dp[n]<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
