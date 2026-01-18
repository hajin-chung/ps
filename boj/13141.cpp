#include <bits/stdc++.h>
#define fi first
#define se second
#define INF 1000000000
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
int d[205][205];
vector<ppi> edges;
int n, m;

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      d[i][j] = i == j ? 0 : INF;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    if (d[u][v] > w) d[u][v] = d[v][u] = w;
    edges.push_back({{u, v}, w});
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (d[i][j] > d[i][k] + d[k][j])
          d[i][j] = d[i][k] + d[k][j];
  double ans = (double)INF;
  for (int i = 1; i <= n; i++) {
    double ret = 0;
    for (auto [uv, w] : edges) {
      auto [u, v] = uv;
      double t = (double)(w+abs(d[i][u]-d[i][v]))/2+min(d[i][u], d[i][v]);
      ret = max(ret, t);
    }
    ans = min(ans, ret);
  }
  printf("%.1lf\n", ans);
}
