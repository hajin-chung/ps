#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9;
int n, m;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, -1, 0, 1};
int a[100][100], num[100][100];
vector<set<int>> tg;
vector<vector<int>> g;

void floodfill(int sy, int sx, int k) {
  tg.resize(k+1);
  num[sy][sx] = k;
  queue<pii> q; q.push({sy, sx});
  while (!q.empty()) {
    auto [yy, xx] = q.front(); q.pop();
    for (int i = 0; i < 4; i++) {
      int ty = yy+dy[i];
      int tx = xx+dx[i];
      if (ty < 0 || ty >= n || tx < 0 || tx >= m) continue;
      if (num[ty][tx] == -1 && a[ty][tx] == a[yy][xx]) {
        num[ty][tx] = k;
        q.push({ty, tx});
      } else if (num[ty][tx] != -1 && a[ty][tx] != a[yy][xx]) {
        tg[k].insert(num[ty][tx]);
        tg[num[ty][tx]].insert(k);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  memset(num, -1, sizeof(num));
  cin>>n>>m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin>>a[i][j];
  int k = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (num[i][j] == -1)
        floodfill(i, j, k++);
  g.resize(k);
  for (int i = 0; i < k; i++)
    for (auto v : tg[i])
      g[i].push_back(v);
  vector<int> order;
  vector<int> chk(k, 0);
  queue<int> q;
  q.push(num[n/2][m/2]);
  chk[num[n/2][m/2]] = 1;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    order.push_back(u);
    for (auto v : g[u])
      if (chk[v] == 0) {
        chk[v] = 1;
        q.push(v);
      }
  }
  int ans = INF;
  for (int i = 0; i < k; i++) {
    int u, d;
    queue<pii> q;
    q.push({order[i], 0});
    while (!q.empty()) {
      u = q.front().fi, d = q.front().se; q.pop();
      if (d >= ans) break;
      for (auto v : g[u])
        if (chk[v] < i+2) {
          chk[v]++;
          q.push({v, d+1});
        }
    }
    while (!q.empty()) q.pop();
    ans = min(ans, d);
  }
  cout<<ans<<"\n";
}
