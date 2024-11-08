#include <bits/stdc++.h>
#define NC 10000
using namespace std;

int n, m;
int w[105], c[105], dp[NC+5];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> w[i];
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i <= NC; i++) dp[i] = -1;
  dp[0] = 0;

  for (int i = 0; i < n; i++) {
    int tmp[NC+5];
    memcpy(tmp, dp, sizeof(dp));
    for (int j = 0; j <= NC; j++) {
      if (dp[j] == -1) continue;
      dp[j+c[i]] = max(tmp[j+c[i]], tmp[j]+w[i]);
    }
  }

  int ans = 0;
  for (int i = 0; i <= NC; i++)
    if (dp[i] >= m) {
      ans = i;
      break;
    }

  cout << ans << "\n";
}
