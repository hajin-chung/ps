#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
const ll MOD = 1e9+7;
vector<int> p;

ll mpow(int n) {
  ll ret = 1;
  while (n--) {
    ret *= 3;
    ret %= MOD;
  }
  return ret;
}

int find(int u) {
  if (u == p[u]) return u;
  return p[u] = find(p[u]);
}

void merge(int u, int v) {
  u = find(u); v = find(v);
  if (u < v) p[v] = u;
  else p[u] = v;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin>>n>>m;
  vector<pii> e(m);
  for (auto &[u, v] : e) cin>>u>>v;
  p.resize(n);
  for (int i = 0; i < n; i++) p[i] = i;
  ll ans = 0;
  for (int i = m-1; i >= 0; i--) {
    auto [u, v] = e[i];
    if ((find(u) == find(0) && find(v) == find(n-1)) ||
        (find(u) == find(n-1) && find(v) == find(0))) {
      ans += mpow(i);
      ans %= MOD;
    } else {
      merge(u, v);
    }
  }
  cout<<ans<<"\n";
}
