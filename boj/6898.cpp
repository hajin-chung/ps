#include <bits/stdc++.h>
using namespace std;

const int N = 150;
const int MAX = 75*151*100;
int n, k, a[N+1], p[N+1]; 
bitset<MAX+1> dp[N+1], t[N+1];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  for (int i = 1; i <= n; i++) {
    cin>>a[i];
    p[i] = p[i-1]+a[i];
  }
  cin>>k;
  dp[0][0] = t[0][0] = 1;
  for (int u = 1; u <= n; u++) {
    for (int i = 0; i < u; i++) {
      t[i+1] |= dp[i]<<(p[u]-p[u-i-1]);
      t[0] |= dp[i];
    }
    for (int i = 0; i <= u; i++) {
      dp[i] = t[i];
      t[i].reset();
    }
  }
  for (int i = k;; i++) {
    if (i > MAX) {
      cout<<i<<"\n";
      return 0;
    }
    bool flag = 1;
    for (int j = 0; j <= n; j++) 
      if (dp[j][i]) 
        flag = 0;
    if (flag) {
      cout<<i<<"\n";
      return 0;
    }
  }
}
