#include <bits/stdc++.h>
using namespace std;

vector<int> p;

int find(int u) {
  if (p[u] == u) return u;
  else return p[u] = find(p[u]);
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u < v) p[v] = u;
  else p[u] = v;
}

int main() {
  int n, m;
  int ans = 0;
  scanf("%d %d", &n, &m);
  p.resize(n+1);
  for (int i = 1; i <= n; i++) p[i] = i;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (ans == 0 && find(u) == find(v)) ans = i+1;
    merge(u, v);
  }
  printf("%d\n", ans);
}
