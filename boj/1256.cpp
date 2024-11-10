#include <bits/stdc++.h>
#define MAX 2000000000
using namespace std;

typedef long long int ll;
int n, m, k;
ll dp[105][105];
char ans[205];

int main() {
  scanf("%d%d%d",&n,&m,&k);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) {
      if (i == 0 || j == 0) dp[i][j] = 1;
      else {
        dp[i][j] = dp[i-1][j] + dp[i][j-1];
        if (dp[i][j] > MAX) dp[i][j] = MAX;
      }
    }
  if (dp[n][m] < k) {
    printf("-1\n");
    return 0;
  }
  int idx = 0, cn = n, cm = m;
  while (!(cn == 0 || cm == 0)) {
    if (cn > 0 && k > dp[cn-1][cm]) {
      ans[idx] = 'z';
      k -= dp[cn-1][cm];
      cm--;
    } else {
      ans[idx] = 'a';
      cn--;
    }
    idx++;
  }
  while(cn--) ans[idx++] = 'a';
  while(cm--) ans[idx++] = 'z';
  printf("%s\n", ans);
}
