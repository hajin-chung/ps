#include <bits/stdc++.h>
#define INF 100000
using namespace std;

char a[55][55];
int islands[55][55], ans[20], check[55][55], vv[2000];
vector<vector<int>> child;
queue<pair<int, int>> Q;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
int sy[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, sx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, m;

int dfs(int s) {
  // printf("s = %d ", s);
  if (child[s].size() == 0) {
    // printf(" 0\n");
    vv[s] = 0;
    return 0;
  }
  int v = 0;
  for (auto c : child[s]) v = max(v, dfs(c));
  // printf(" %d\n", v);
  return vv[s] = v + 1;
}

void init_check() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      check[i][j] = 0;
}

int main() {
  int i, j, k;
  int cnt = 0;
  vector<pair<int, int>> starts;

  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++)
    scanf("%s", a[i]);

  starts.push_back({-1, -1});
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (a[i][j] == 'x' && islands[i][j] == 0) {
        cnt++;
        islands[i][j] = cnt;
        starts.push_back({i, j});
        Q.push({i, j});
        while (!Q.empty()) {
          auto [yy, xx] = Q.front();
          Q.pop();
          for (k = 0; k < 8; k++) {
            int ty = yy + sy[k];
            int tx = xx + sx[k];
            if (ty < 0 || ty >= n || tx < 0 || tx >= m) continue;
            if (islands[ty][tx] != 0) continue;
            if (a[ty][tx] == '.') continue;
            islands[ty][tx] = cnt;
            Q.push({ty, tx});
          }
        }
      }
  child.resize(cnt + 1);
  for (i = 1; i <= cnt; i++) {
    init_check();
    check[starts[i].first][starts[i].second] = 1;
    Q.push(starts[i]);
    set<int> wrappers;
    while (!Q.empty()) {
      auto [yy, xx]  = Q.front();
      Q.pop();
      for (k = 0; k < 4; k++) {
        int ty = yy + dy[k];
        int tx = xx + dx[k];
        if (ty < 0 || ty >= n || tx < 0 || tx >= m) continue;
        if (check[ty][tx]) continue;
        if (islands[ty][tx] == 0 || islands[ty][tx] == i) {
          Q.push({ty, tx});
          check[ty][tx] = 1;
        } else if (islands[ty][tx] < i) {
          wrappers.insert(islands[ty][tx]);
        }
      }
    }
    while (!Q.empty()) Q.pop();
    printf("%d's wrappers: ", i);
    for (auto ww : wrappers) {
      printf("%d ", ww);
    }
    printf("\n");
    if (wrappers.size() == 1) {
      child[*wrappers.begin()].push_back(i);
    }
  }
  int mc = -1;

  printf("\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (islands[i][j] == 0) printf(".");
      else printf("%d", islands[i][j]);
    }
    printf("\n");
  }

  // for (auto i : child) {
  //   for (auto j : i) {
  //     printf("%d ", j);
  //   }
  //   printf("\n");
  // }

  for (i = 1; i <= cnt; i++) vv[i] = -1;
  for (i = 1; i <= cnt; i++) if (vv[i] == -1) dfs(i);

  // for (i = 1; i <= cnt; i++) {
  //   printf("%d ", vv[i]);
  // }
  // printf("\n");
  
  for (i = 1; i <= cnt; i++) {
    ans[vv[i]]++;
    mc = max(mc, vv[i]);
  }

  if (mc == -1) printf("-1");
  else for (i = 0; i <= mc; i++) printf("%d ", ans[i]);
  printf("\n");
}
