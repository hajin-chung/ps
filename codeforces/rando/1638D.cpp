#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

const int N = 1000;
vector<tuple<int, int, int>> ans;
int a[N+5][N+5];
int n, m; 

void color(int i, int j, int c) {
  a[i][j] = a[i-1][j] = a[i][j-1] = a[i-1][j-1] = c;
}

int check(int y, int x, int c) {
  return a[y][x] == 0 || a[y][x] == c;
}

int check(int y, int x) {
  int c = max({a[y][x], a[y-1][x], a[y][x-1], a[y-1][x-1]});
  bool b = check(y, x, c);
  b &= check(y, x-1, c);
  b &= check(y-1, x-1, c);
  b &= check(y-1, x, c);
  if (b) return c;
  return 0;
}

void rec(int yy, int xx) {
  for (int ty = max(2, yy-1); ty <= min(n, yy+1); ty++)
    for (int tx = max(2, xx-1); tx <= min(m, xx+1); tx++) {
      int c = check(ty, tx);
      if (c > 0) {
        color(ty, tx, 0);
        ans.push_back({ty, tx, c});
        rec(ty, tx);
      }
    }
}

void f() {
  cin>>n>>m;
  queue<pair<int, int>> q;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin>>a[i][j];
      if (a[i][j] == a[i-1][j] && a[i][j] == a[i-1][j-1] && a[i][j] == a[i][j-1]) {
        ans.push_back({i, j, a[i][j]});
        color(i, j, 0);
        q.push({i, j});
      }
    }

  while (!q.empty()) {
    auto [yy, xx] = q.front(); q.pop();
    rec(yy, xx);
  }

  bool flag = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j])
        flag = 0;

  if (!flag) {
    cout<<"-1\n";
    return;
  }

  cout<<sz(ans)<<"\n";
  reverse(all(ans));
  for (auto [y, x, c] : ans) cout<<y-1<<" "<<x-1<<" "<<c<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  f();
}
