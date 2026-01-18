#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int abs(int x) {
  return x>0 ? x : -x;
}
int w, h, mdist, s2x, s2y, s3x, s3y, ans;
int mp[9][9];
char dx[] = { 1, 0, -1, 0 };
char dy[] = { 0, 1, 0, -1 };

bool outBoard(int x, int y) {
  return (x<0 || h <= x || y<0 || w <= y);
}

int bfs(int step) {
  bool visit[9][9];
  memset(visit, false, sizeof(visit));
  queue<pair<int, pair<int, int>>>qu;
  qu.push(make_pair(0, make_pair(s3x, s3y)));
  while (!qu.empty()) {
      pair<int, pair<int, int>> p = qu.front();
      qu.pop();
      int s = p.first, x = p.second.first, y = p.second.second;
      if (s + step + 1 >= ans) return -1;
      if (visit[x][y]) continue;
      visit[x][y] = true;
      for (int i = 0; i<4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (outBoard(nx, ny) || visit[nx][ny]) continue;
      if (mp[nx][ny] == 5) return s + 1;
      if (mp[nx][ny] == 0) qu.push(make_pair(s + 1, make_pair(nx, ny)));
    }
  }
  return -1;
}

void dfs(int x, int y, int p0, int p1, int p2, int p3, int step) {
  if (step + mdist >= ans) return;
  bool check = false;
  for (int i = 0; i<4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (outBoard(nx, ny)) continue;
    if (mp[nx][ny] == 4) check = true;
  }
  if (check) {
    int cost = bfs(step);
    if (cost != -1) ans = step + cost;
  } else {
    for (int i = 0; i<4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (outBoard(nx, ny) || mp[nx][ny] != 0) continue;
      int count = 0;
      for (int j = 0; j<4; j++) {
        int nnx = nx + dx[j], nny = ny + dy[j];
        if (outBoard(nnx, nny)) continue;
        if (mp[nnx][nny] == 6 || mp[nnx][nny] == 2) count++;
      }
      if (count>1) continue;
      if (p1 == p0 && (i - p2 + 4) % 4 == 2 && (i + p1) % 2 == 1 
          && mp[nx - dx[p0]][ny - dy[p0]] == 0) continue;
      if (p2 == p1 && p1 == p0 && (i - p3 + 4) % 4 == 2 && (i + p2) % 2 == 1
          && mp[nx - dx[p0]][ny - dy[p0]] == 0 
          && mp[nx - 2 * dx[p0]][ny - 2 * dy[p0]] == 0) continue;
      mp[nx][ny] = 6;
      dfs(nx, ny, i, p0, p1, p2, step + 1);
      mp[nx][ny] = 0;
    }
  }
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> h >> w;
    bool flag2 = true, flag3 = true;
    ans = 100;
    for (int i = 0; i<h; i++) {
      for (int j = 0; j<w; j++) {
         cin >> mp[i][j];
         if (mp[i][j] == 2) {
           if (flag2) mp[i][j] = 4, flag2 = false;
           else s2x = i, s2y = j;
         }
         if (mp[i][j] == 3) {
           if (flag3) s3x = i, s3y = j, mp[i][j] = 5, flag3 = false;
           else mdist = abs(s3x - i) + abs(s3y - j), s3x = i, s3y = j;
         }
       }
    }
    dfs(s2x, s2y, 6, 7, 8, 9, 1);
    cout << (ans == 100 ? 0 : ans) << endl;
  }
}
