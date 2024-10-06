#include <bits/stdc++.h>
using namespace std;

int a[301][301], d[301][301];

int main() {
  int n, i, j, k, mx = -1000;
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
      d[i][j] = d[i-1][j] + d[i][j-1] - d[i-1][j-1] + a[i][j];
    }

  for (k = 1; k <= n; k++)
    for (i = k; i <= n; i++)
      for (j = k; j <= n; j++) {
        int s = d[i][j] - d[i-k][j] - d[i][j-k] + d[i-k][j-k];
        if (s > mx) mx = s;
      }
  printf("%d\n", mx);

  return 0;
}
