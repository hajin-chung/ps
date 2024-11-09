#include <bits/stdc++.h>
using namespace std;

string a, b;
int dp[4005][4005];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>a>>b;
  int ans = 0;
  for (int i = 0; i < a.size(); i++)
    for (int j = 0; j < b.size(); j++)
      if (a[i] == b[j]) {
        dp[i][j] = ((i>0 && j>0) ? dp[i-1][j-1] : 0) + 1;
        ans = max(ans, dp[i][j]);
      }
  cout<<ans<<"\n";
}
