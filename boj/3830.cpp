#include <bits/stdc++.h>
#define N 100000
using namespace std;

int d[N+5], p[N+5];

int find(int u) {
  if (p[u] == u) return u;
  int pu = find(p[u]);
  d[u] += d[p[u]];
  return p[u] = pu;
}

void merge(int u, int v, int w) {
  int pu = find(u);
  int pv = find(v);
  if (pu != pv) {
    d[pv] = -d[v] + d[u] + w;
    p[pv] = pu;
  }
}

bool solve() {
  int n, m;
  cin >> n >> m;
  if (n == 0 && m == 0) return false;
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    d[i] = 0;
  }

  while (m--) {
    char q;
    cin >> q;
    if (q == '!') {
      int u, v, w;
      cin >> u >> v >> w;
      merge(u, v, w);
    } else if (q == '?') {
      int u, v;
      cin >> u >> v;
      int pu = find(u);
      int pv = find(v);
      if (pu == pv) cout << d[v] - d[u] << "\n";
      else cout << "UNKNOWN" << "\n";
    }
  }
  return true;
}

int main() {
  /*cin.tie(0);*/
  /*ios::sync_with_stdio(false);*/
  while (solve()) {}
}
