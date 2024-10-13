#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

int a[55][55], d[55][55], check[55][55], ans[2000];
int n, m, icnt, mh = -1;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
int sy[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, sx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<pii> starts;
vector<vector<int>> adj;

int dfs(int curr) {
  int h = -1;
  for (auto next : adj[curr]) h = max(h, dfs(next));
  h++;
  if (curr != 0) {
    mh = max(h, mh);
    ans[h]++;
  }
  return h;
}

int main() {
  int i, j, k;

  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++) {
    char tmp[55];
    for (j = 0; j < 55; j++) tmp[j] = 0;
    scanf("%s", &tmp[1]);
    for (j = 1; j <= m; j++) a[i][j] = tmp[j] == 'x';
  }

  starts.push_back({0, 0});
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (d[i][j] == 0 && a[i][j] == 1) {
        icnt++;
        d[i][j] = icnt;
        starts.push_back({i, j});
        queue<pii> Q;
        Q.push({i, j});
        while (!Q.empty()) {
          auto [yy, xx] = Q.front();
          Q.pop();
          for (k = 0; k < 8; k++) {
            int ty = yy + sy[k];
            int tx = xx + sx[k];
            if (ty <= 0 || ty > n || tx <= 0 || tx > m) continue;
            if (a[ty][tx] == 1 && d[ty][tx] == 0) {
              d[ty][tx] = icnt;
              Q.push({ty, tx});
            }
          }
        }
      }

  adj.resize(icnt+1);

  queue<pii> Q;
  for (i = 0; i <= icnt; i++) {
    int parent = -1;
    bool flag = false;
    Q.push(starts[i]);
    while (!Q.empty()) {
      auto [yy, xx] = Q.front();
      Q.pop();
      for (j = 0; j < 4; j++) {
        int ty = yy + dy[j];
        int tx = xx + dx[j];
        if (ty < 0 || ty > n+1 || tx < 0 || tx > m+1) continue;
        if (d[ty][tx] == i && !check[ty][tx]) {
          check[ty][tx] = 1;
          Q.push({ty, tx});
        } else if (d[ty][tx] < 0) {
          if (parent > 0 && parent != -d[ty][tx] - 1) flag = true;
          else parent = -d[ty][tx] - 1;
        }
      }
    }
    if (!flag && parent >= 0) adj[parent].push_back(i);

    d[starts[i].first][starts[i].second] = -i - 1;
    Q.push(starts[i]);
    while (!Q.empty()) {
      auto [yy, xx] = Q.front();
      Q.pop();
      for (j = 0; j < 4; j++) {
        int ty = yy + dy[j];
        int tx = xx + dx[j];
        if (ty < 0 || ty > n+1 || tx < 0 || tx > m+1) continue;
        if (d[ty][tx] == 0 || d[ty][tx] == i) {
          d[ty][tx] = -i - 1;
          Q.push({ty, tx});
        }
      }
    }
  }
  dfs(0);
  if (mh == -1) printf("-1");
  else for (i = 0; i <= mh; i++) printf("%d ", ans[i]);
  printf("\n");
}
