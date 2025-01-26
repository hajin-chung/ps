#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
struct E {
  int u, v;
  ll c, t;
};
const int N = 400;
int n, m; 
ll f; 
vector<E> edges;
int p[N+1];

int find(int u) {
  if (u == p[u]) return u;
  return p[u] = find(p[u]);
}

void merge(int u, int v) {
  u = find(u); v = find(v);
  if (u < v) p[v] = u;
  else p[u] =v;
}

bool chk(ld k) {
  for (int i = 1; i <= n; i++) p[i] = i;
  sort(edges.begin(), edges.end(), [&](E &a, E &b) {
    return (ld)a.c+k*a.t < (ld)b.c+k*b.t;
  });
  int cnt = 0;
  ll csum = 0, tsum = 0;
  for (auto [u, v, c, t] : edges) {
    if (find(u) != find (v)) {
      merge(u, v);
      cnt++;
      csum+=c; tsum+=t;
      if (cnt-1 == n) break;
    }
  }
  if (cnt < n-1) return 0;
  return (ld)csum+k*tsum<=(ld)f;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>m>>f;
  edges.resize(m);
  for (auto &[u, v, c, t] : edges) cin>>u>>v>>c>>t;
  ld l = 0, r = f;
  int iter = 100;
  while (iter--) {
    ld k = (l+r)/2;
    if (chk(k)) l = k;
    else r = k;
  }
  cout<<fixed<<setprecision(4)<<(l+r)/2<<"\n";
}
