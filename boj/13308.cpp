#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef pair<pll, int> ppi;
ll d[2505][2505];
const ll INF = 1LL*2500*2500*4000 + 10;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin>>n>>m;
  vector<ll> c(n);
  vector<vector<pil>> a(n);
  for (auto &i : c) cin>>i;
  for (int i = 0; i < m; i++) {
    int u, v; ll w; cin>>u>>v>>w;
    a[u-1].push_back({v-1, w});
    a[v-1].push_back({u-1, w});
  }
  for (int i = 0; i < n; i++)
    for (int j = 1; j <= 2500; j++)
      d[i][j] = INF;
  priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
  pq.push({{0, c[0]}, 0});
  while (!pq.empty()) {
    auto [dw, u] = pq.top(); pq.pop();
    auto [ud, uc] = dw;
    if (d[u][uc] < ud) continue;
    for (auto [v, vd] : a[u])
      if (d[v][uc] > ud + uc*vd) {
        d[v][uc] = ud + uc*vd;
        pq.push({{d[v][uc], min(uc, c[v])}, v});
      }
  }
  ll ans = INF;
  for (int i = 1; i <= 2500; i++) ans = min(ans, d[n-1][i]);
  cout<<ans<<"\n";
}
