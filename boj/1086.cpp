#include <bits/stdc++.h>
#define N 15
#define K 100
using namespace std;

int n, k;
int dp[N+1][K+1], a[N+1];

int dcnt(int x) {
  int ret = 1;
  while (x/=10) ret++;
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>k;
  vector<string> t(n+1);
  for (int i = 1; i <= n; i++) cin>>t[i];
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < t.size(); j++) {
      a[i] *= 10;
      a[i] += (t[i][j]-'0');
      a[i] %= k;
    }
}
