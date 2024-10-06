/*
 * Could not solve
 * solution is run three dijikstras two for the prisoners and 
 * one for sanggun
 * then loop through each space (not wall) and get the distance to each person
 * minimum of the distance sum is the answer
 * triangulating stuff!!!
 * */

#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 10000000

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pip;

int d[3][105][105];
char a[105][105];
int dy[4] = {0, 1, 0, -1}, dx[4] = {-1, 0, 1, 0};
int n, m;
priority_queue<pip, vector<pip>, greater<pip>> Q;

void BFS(int idx, pii ss) {
  int i, j;
  d[idx][ss.first][ss.second] = 0;
  Q.push({0, ss});
  while(!Q.empty()) {
    pip f = Q.top(); Q.pop();
    int yy = f.second.first, xx = f.second.second;
    for (i = 0; i < 4; i++) {
      int ty = yy + dy[i];
      int tx = xx + dx[i];
      if (ty < 0 || ty > n + 1 || tx < 0 || tx > m + 1) continue;
      if (a[ty][tx] == '*') continue;
      int isDoor = a[ty][tx] == '#';
      if (d[idx][ty][tx] > d[idx][yy][xx] + isDoor) {
        d[idx][ty][tx] = d[idx][yy][xx] + isDoor;
        Q.push({d[idx][ty][tx], {ty, tx}});
      }
    }
  }
}

void solve() {
  char tmp[105];
  int i, j, k;
  bool discovered = false;
  pii p1, p2;

  for (i = 0; i < 105; i++)
    for (j = 0; j < 105; j++)
      a[i][j] = '.';

  scanf("%d %d", &n, &m);

  for (k = 0; k < 3; k++)
    for (i = 0; i <= n + 1; i++)
      for (j = 0; j <= m + 1; j++)
        d[k][i][j] = INF;

  for (i = 1; i <= n; i++) {
    scanf("%s", &tmp[1]);
    for (j = 1; j <= m; j++) {
      a[i][j] = tmp[j];
      if (tmp[j] == '$') {
        if (!discovered) {
          p1 = { i, j };
          discovered = true;
        } else p2 = { i, j };
      }
    }
  }

  BFS(0, p1);
  BFS(1, p2);
  BFS(2, {0, 0});

  int mn = INF;
  for (i = 0; i <= n + 1; i++)
    for (j = 0; j <= m + 1; j++) {
      int sm = 0;
      for (k = 0; k < 3; k++) sm += d[k][i][j];
      if (a[i][j] == '#') sm -= 2;
      if (sm < mn) mn = sm;
    }
  printf("%d\n", mn);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) solve();
}
