#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int N = 50;
int n;
ll dp[N+1][N+1], k;

ll f(int i, int j) {
  if (j < 0) return 0;
  if (i == n) return j == 0;
  ll &ret = dp[i][j];
  if (ret != -1) return ret;
  return ret = f(i+1, j+1)+f(i+1, j-1);
}

void g(int i, int j, ll k) {
  if (i == n) return;
  if (f(i+1, j+1)<=k) {
    cout<<")";
    g(i+1, j-1, k-f(i+1, j+1));
  } else {
    cout<<"("; 
    g(i+1, j+1, k);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>k;
  memset(dp, -1, sizeof(dp));
  if (f(0, 0) <= k) cout<<"-1";
  else g(0, 0, k);
  cout<<"\n";
}
