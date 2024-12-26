#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
typedef pair<double, pii> pdp;
typedef pair<double, double> pdd;
int p[1005];

int find(int u) {
  if (p[u] == u) return u;
  return p[u] = find(p[u]);
}

void merge(int u, int v) {
  u = find(u); v = find(v);
  if (u < v) p[v] = u;
  else p[u] = v;
}

double dist(pdd a, pdd b) {
  double dx = a.fi-b.fi;
  double dy = a.se-b.se;
  return sqrt(dx*dx+dy*dy);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  double m, n; int k; cin>>m>>n>>k;
  vector<pdd> pillar(k);
  for (auto &[x, y] : pillar) cin>>x>>y;
  vector<pdp> a;
  for (int i = 0; i < k-1; i++)
    for (int j = i+1; j < k; j++)
      a.push_back({dist(pillar[i], pillar[j]), {i, j}});
  for (int i = 0; i < k; i++) {
    a.push_back({pillar[i].se, {i, k}});
    a.push_back({n - pillar[i].se, {i, k+1}});
    a.push_back({pillar[i].fi, {i, k+2}});
    a.push_back({m - pillar[i].fi, {i, k+3}});
  }
  a.push_back({n, {k, k+1}});
  a.push_back({m, {k+2, k+3}});
  k += 4;
  for (int i = 0; i < k; i++) p[i] = i;
  sort(a.begin(), a.end());
  double ans;
  for (int i = 0; i < a.size(); i--) {
    auto [d, uv] = a[i];
    auto [u, v] = uv;
    ans = d;
    if (find(u) != find(v)) merge(u, v);
    if (find(k-1) == find(k-2) 
        && find(k-3) == find(k-4) 
        && find(k-1) == find(k-3)) {
      break;
    }
  }
  cout<<fixed<<setprecision(8)<<ans/2<<"\n";
}
