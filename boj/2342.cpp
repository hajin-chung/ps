#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int t[5][5], dp[5][5];

int score(int pi, int pj, int ni, int nj) {
  if (pi != ni && pj != nj) return INF;
  if (pi == ni) {
    swap(pi, pj);
    swap(ni, nj);
  }

  if (pi == ni) return 1;
  if (pi == 0) return 2;
  if ((ni+1)%4 == pi%4 || (pi+1)%4 == ni%4) return 3;
  if (abs(ni-pi) == 2) return 4;
  return INF;
}

int main() {
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      t[i][j] = INF;
  t[0][0] = 0;
  while (1) {
    int a;
    scanf("%d", &a);
    if (a == 0) break;
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++)
        dp[i][j] = INF;
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++)
        if (i == a || j == a)
          for (int pi = 0; pi < 5; pi++)
            for (int pj = 0; pj < 5; pj++)
              dp[i][j] = min(dp[i][j], t[pi][pj]+score(pi, pj, i, j));
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++) {
        if (i == a || j == a) t[i][j] = dp[i][j];
        else t[i][j] = INF;
      }
  }
  int ans = INF;
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      ans = min(ans, t[i][j]);
  printf("%d\n", ans);
}
