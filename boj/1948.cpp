#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

typedef pair<int, int> pii;

vector<int> ind, d, chk;
vector<vector<pii>> a, ra;
int n, m, cnt, s, e;

void dfs(int curr) {
  if (chk[curr]) return;
  chk[curr] = 1;

  for (auto [next, w] : ra[curr]) {
    if (d[next] == d[curr] - w) {
      cnt++;
      dfs(next);
    }
  }
}

int main() {
  int i, j;
  int x, y, z;

  scanf("%d %d", &n, &m);
  a.resize(n+1);
  ra.resize(n+1);
  d.resize(n+1);
  ind.resize(n+1);
  chk.resize(n+1);
  for (i = 0; i < m; i++) {
    scanf("%d %d %d", &x, &y, &z);
    a[x].push_back({y, z});
    ra[y].push_back({x, z});
    ind[y]++;
  }
  scanf("%d %d", &s, &e);

  queue<int> Q;
  Q.push(s);
  d[s] = 0;
  while (!Q.empty()) {
    int curr = Q.front();
    Q.pop();
    for (auto [next, w] : a[curr]) {
      if (d[next] < d[curr] + w) d[next] = d[curr] + w;
      if (--ind[next] == 0) Q.push(next);
    }
  }
  dfs(e);
  printf("%d\n%d\n", d[e], cnt);
}
