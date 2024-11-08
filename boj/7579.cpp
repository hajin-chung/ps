#include <bits/stdc++.h>
using namespace std;

int n, m;
int w[105], c[105], dp[10005];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> w[i];
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < 10000; i++) dp[i] = -1;
  dp[0] = 0;

  for (int i = 0; i < n; i++) {
    int tmp[10005];
    memcpy(tmp, dp, sizeof(dp));
    for (int j = 0; j < 10000; j++) {
      if (dp[j] == -1) continue;
      dp[j+c[i]] = max(tmp[j+c[i]], tmp[j]+w[i]);
    }
  }

  int ans = 0;
  for (int i = 0; i < 10000; i++)
    if (dp[i] >= m) {
      ans = i;
      break;
    }

  cout << ans << "\n";
}
