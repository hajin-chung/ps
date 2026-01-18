#include <bits/stdc++.h>
#define INF 1000000000
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
int n, m, dp[1005][1005];
pii a[1005], p[1005][1005];

int dist(int curr, int next, int t) { 
  pii u = a[curr], v = a[next];
  if (curr == 0) {
    if (t == 2) u = {n, n};
    else u = {1, 1};
  }
  return abs(u.fi-v.fi)+abs(u.se-v.se);
}

int main() {
  scanf("%d%d",&n,&m);
  for (int i = 1; i <= m; i++)
    scanf("%d%d", &a[i].fi, &a[i].se);
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= m; j++)
       dp[i][j] = INF;
  dp[0][0] = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++) {
      int k = max(i, j)+1;
      if (j != k && dp[i][k] > dp[i][j]+dist(j, k, 2)) {
        dp[i][k] = dp[i][j]+dist(j, k, 2);
        p[i][k] = {i, j};
      }
      if (i != k && dp[k][j] > dp[i][j]+dist(i, k, 1)) {
        dp[k][j] = dp[i][j]+dist(i, k, 1);
        p[k][j] = {i, j};
      }
    }

  int ans = INF;
  vector<int> path;
  pii curr;
  for (int i = 0; i < m; i++) {
    if (ans > dp[i][m]) {
      ans = dp[i][m];
      curr = {i, m};
    }
    if (ans > dp[m][i]) {
      ans = dp[m][i];
      curr = {m, i};
    }
  }
  printf("%d\n", ans);
  while (curr.fi != 0 || curr.se != 0) {
    pii next = p[curr.fi][curr.se];
    if (next.fi != curr.fi) path.push_back(1);
    else path.push_back(2);
    curr = next;
  }
  for (auto iter = path.rbegin(); iter != path.rend(); iter++)
    printf("%d\n", *iter);
}
