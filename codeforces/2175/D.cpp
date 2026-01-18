#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void solve() {
  int n, k; cin>>n>>k;
  vector<int> a(n); for (auto &x: a) cin>>x;
  int mx = 0;
  for (auto &x: a) {
    if (x > mx) x = 0;
    else mx = x;
  }

  vector<vector<pii>> dp(n, vector<pii>(k+1));
  for (int i = 0; i < min(a[0], k); i++) dp[0][i] = {i, i};
  for (int i = 1; i < n; i++) {
    if (a[i] == 0)
      for (int j = 0; j <= k; j++) 
        dp[i][j] = {dp[i-1][j].fi+dp[i-1][j].se, dp[i-1][j].se};
    else {
      int 
      for (int j = 0; j <= k; j++)
        dp[i][j] = {}
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) solve();
}
