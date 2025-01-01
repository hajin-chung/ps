#include <bits/stdc++.h>
#define INF 1000000000
#define MAX 100000
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) {
    int n; cin>>n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin>>a[i]>>b[i];
    vector<int> dp(MAX, INF); dp[0] = 0;
    for (int i = 0; i < n; i++) for (int j = MAX; j >= 0; j--) {
      dp[j] += b[i];
      if (j - a[i] >= 0) dp[j] = min(dp[j], dp[j-a[i]]);
    }
    int ans = INF;
    for (int i = 0; i < MAX; i++) ans = min(ans, max(i, dp[i]));
    cout<<ans<<"\n";
  }
}
