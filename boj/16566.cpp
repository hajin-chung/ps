#include <bits/stdc++.h>
using namespace std;

vector<int> c, parent;

int get_parent(int x) {
  if (parent[x] == x) return x;
  else return parent[x] = get_parent(parent[x]);
}

void union_parent(int a, int b) {
  if (b >= c.size()) return;
  int pa = get_parent(a);
  int pb = get_parent(b);
  parent[pa] = pb;
}

int ub(int x) {
  int l = 0, h = c.size();
  while (l < h) {
    int mid = (l + h) >> 1;
    if (c[mid] <= x) l = mid + 1;
    else h = mid;
  }
  return h;
}

int main() {
  int n, m, k, i, x;
  scanf("%d %d %d", &n, &m, &k);
  c.resize(m);
  parent.resize(m);
  for (i = 0; i < m; i++) parent[i] = i;
  for (i = 0; i < m; i++) scanf("%d", &c[i]);

  sort(c.begin(), c.end());
  for (i = 0; i < k; i++) {
    scanf("%d", &x);
    int u = get_parent(ub(x));
    printf("%d\n", c[u]);
    union_parent(u, u+1);
  }
  return 0;
}
