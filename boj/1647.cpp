#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n, m;
vector<int> p;
vector<vector<pii>> a;
vector<tuple<int, int, int>> edges;

int find(int a) {
  if (p[a] == a) return a;
  else return p[a] = find(p[a]);
}

void merge(int a, int b) {
  a = find(a); 
  b = find(b);
  if (a < b) p[b] = a;
  else p[a] = b;
}

int main() {
  int i, j;
  int x, y, z, me = 0, sum = 0;

  scanf("%d %d", &n, &m);
  a.resize(n+1);
  for (i = 0; i < m; i++) {
    scanf("%d %d %d", &x, &y, &z);
    a[x].push_back({y, z});
    a[y].push_back({x, z});
    edges.push_back({z, x, y});
  }

  p.resize(n+1);
  for (i = 1; i <= n; i++) p[i] = i;

  sort(edges.begin(), edges.end());
  for (auto edge : edges) {
    auto [z, x, y] = edge;
    if (find(x) == find(y)) continue;
    merge(x, y);
    sum += z;
    me = max(me, z);
  }
  printf("%d\n", sum - me);
}
