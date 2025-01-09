#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;
int dp[1005][1005];
string str;

int f(int s, int e) {
  if (s > e) return 0;
  if (s == e) return 1;

  int &ret = dp[s][e];
  if (ret != -1) return ret;

  ret = (f(s, e-1)+f(s+1, e)-f(s+1,e-1)+MOD)%MOD;
  if (str[s] == str[e]) ret = (ret+f(s+1, e-1)+1)%MOD;
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>str;
  memset(dp, -1, sizeof(dp));
  cout<<f(0, str.size()-1)<<"\n";
}
