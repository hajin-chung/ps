#include <bits/stdc++.h>
using namespace std;

int n, k;
int dp[1005][1005];

int main() {
  scanf("%d%d",&n,&k);
  dp[1][1] = 1;
  dp[2][1] = 2;
  dp[3][1] = 3;
  for (int i = 4; i <= n; i++)
    for (int j = 1; j <= i/2; j++)
      dp[i][j] = (dp[i-1][j] + dp[i-2][j-1])%1000000003;
  printf("%d\n",dp[n][k]);
}
