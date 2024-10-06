#include <bits/stdc++.h>
#define fi first
#define se second
#define INF 1000000000
using namespace std;

typedef pair<int, int> pii;

int n, m, s, e;
vector<vector<pii>> a;
vector<int> path, d;
priority_queue<pii, vector<pii>, greater<pii>> Q;

int main() {
  int i, x, y, z;

  scanf("%d %d", &n, &m);
  a.resize(n+1);
  path.resize(n+1);
  d.resize(n+1, INF);
  for (i = 0; i < m; i++) {
    scanf("%d %d %d", &x, &y, &z);
    a[x].push_back({y, z});
  }
  scanf("%d %d", &s, &e);

  d[s] = 0;
  Q.push({0, s});
  while (!Q.empty()) {
    pii pp = Q.top();
    Q.pop();

    if (d[pp.se] < pp.fi) continue;

    for (i = 0; i < a[pp.se].size(); i++) {
      pii tt = a[pp.se][i];
      if (d[tt.fi] > d[pp.se] + tt.se) {
        d[tt.fi] = d[pp.se] + tt.se;
        path[tt.fi] = pp.se;
        Q.push({d[tt.fi], tt.fi});
      }
    }
  }

  printf("%d\n", d[e]);
  stack<int> ans;
  int cur = e;
  while (cur != s) {
    ans.push(cur);
    cur = path[cur];
  }
  ans.push(s);
  printf("%d\n", ans.size());
  while (!ans.empty()) {
    printf("%d ", ans.top());
    ans.pop();
  }
  printf("\n");
}
