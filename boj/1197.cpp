#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long int ll;

int n, m;
vector<tuple<ll, int, int>> e;
vector<int> parent;

int find(int p) {
  if (parent[p] == p) return p;
  else return parent[p] = find(parent[p]);
}

void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a > b) parent[a] = b;
  else parent[b] = a;
}

int main() {
  int i, j, u, v;
  ll w, sum = 0;

  scanf("%d %d", &n, &m);
  for (i = 0; i < m; i++) {
    scanf("%d %d %lld", &u, &v, &w);
    e.pb({w, u-1, v-1});
  }
  parent.resize(n);
  for (i = 0; i < n; i++) parent[i] = i;

  sort(e.begin(), e.end());
  for (i = 0; i < m; i++) {
    auto [w, a, b] = e[i];
    if (find(a) == find(b)) continue;
    merge(a, b);
    sum += w;
  }
  printf("%lld\n", sum);
}
