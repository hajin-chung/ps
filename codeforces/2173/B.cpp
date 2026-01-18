#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void solve() {
  int n; cin>>n;
  vector<int> a(n); for (auto &x: a) cin>>x;
  vector<int> b(n); for (auto &x: b) cin>>x;
  vector<vector<ll>> dp(4, vector<ll>(n));
  dp[2][0] = dp[0][0] = -a[0];
  dp[3][0] = dp[1][0] = b[0];
  for (int i = 1; i < n; i++) {
    dp[0][i] = max(dp[0][i-1], dp[1][i-1]) - a[i];
    dp[1][i] = b[i] - min(dp[2][i-1], dp[3][i-1]);
    dp[2][i] = min(dp[2][i-1], dp[3][i-1]) - a[i];
    dp[3][i] = b[i] - max(dp[0][i-1], dp[1][i-1]);
  }
  cout<<max(dp[0][n-1], dp[1][n-1])<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) solve();
}
