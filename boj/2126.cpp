#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
struct E {
  int u, v;
  ll c, t;
};
const int N = 400;
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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; ll f; cin>>n>>m>>f;
  vector<E> edges(m);
  for (auto &[u, v, c, t] : edges) cin>>u>>v>>c>>t;
  for (int i = 1; i <= n; i++) p[i] = i;
  vector<bool> chk(m, 0);
  ll csum = 0, tsum = 0; n--;
  while (n--) {
    vector<E> e;
    for (int i = 0; i < m; i++)
      if (!chk[i]) e.push_back(edges[i]);
    sort(e.begin(), e.end(), [&](E &a, E &b) {
      ld ae = (ld)(f-(csum+a.c))/(tsum+a.t);
      ld be = (ld)(f-(csum+b.c))/(tsum+b.t);
      return ae > be;
    });
    for (int i = 0; i < e.size(); i++) {
      auto [u, v, c, t] = e[i];
      if (find(u) != find(v)) {
        merge(u, v);
        csum += c; tsum += t;
        chk[i] = 1;
        break;
      }
    }
  }
  cout<<fixed<<setprecision(10)<<(ld)(f-csum)/tsum<<"\n";
}
