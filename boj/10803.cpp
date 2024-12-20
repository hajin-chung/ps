#include <bits/stdc++.h>
using namespace std;

int dp[10001][101];

int go(int w, int h) {
  if (dp[w][h]) return dp[w][h];
  if (w == h) return dp[w][h] = 1;
  int ret = INT_MAX;
  /*cout<<w<<" "<<h<<endl;*/
  for (int i = 1; i < w; i++) ret = min(ret, go(i, h) + go(w-i, h));
  for (int i = 1; i < h; i++) ret = min(ret, go(w, i) + go(w, h-i));
  return dp[w][h] = ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin>>n>>m;
  for (int i = 1; i <= min(n, m); i++) dp[i][i] = 1;
  cout<<go(n, m)<<"\n";
}
