#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
int d[2505][2505];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin>>n>>m;
  cout<<"hi"<<endl;
  vector<int> c(n);
  vector<vector<pii>> a(n);
  for (auto &i : c) cin>>i;
  for (int i = 0; i < m; i++) {
    int u, v, w; cin>>u>>v>>w;
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
  int ans = INF;
  for (int i = 1; i <= 2500; i++) ans = min(ans, d[n-1][i]);
  cout<<ans<<"\n";
}
