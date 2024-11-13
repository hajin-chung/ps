#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define INF 1000000000
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pip;
int n, m, k, q;
vector<int> festivals, p;
vector<pii> queries, lr;

vector<pip> dij(vector<vector<pii>> &edges) {
  vector<pip> e;
  vector<int> d(n+1);
  for (auto f : festivals) 
    edges[0].push_back({f, 0});
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  for (int i = 0; i <= n; i++)
    d[i] = INF;
  d[0] = 0;
  pq.push({0, 0});
  while (!pq.empty()) {
    auto [dist, curr] = pq.top(); pq.pop();
    if (dist > d[curr]) continue;
    for (auto [next, w]: edges[curr])
      if (d[next] > d[curr] + w) {
        d[next] = d[curr] + w;
        pq.push({d[next], next});
      }
  }
  for (int curr = 1; curr <= n; curr++)
    for (auto [next, w] : edges[curr])
      if (curr < next && next != 0 && curr != 0) {
        e.push_back({min(d[curr], d[next]), {curr, next}});
      }
  return e;
}

int find(int u) {
  if (p[u] == u) return u;
  return p[u] = find(p[u]);
}

void merge(int u, int v) {
  u = find(u); 
  v = find(v); 
  if (u < v) p[v] = u;
  else p[u] = v;
}

bool comp(pip a, pip b) {
  if (a.fi == b.fi) return a.se > b.se;
  return a.fi > b.fi;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>m>>k>>q;
  vector<vector<pii>> edges;
  edges.resize(n+1);
  p.resize(n+1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin>>u>>v>>w;
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }
  for (int i = 0; i < k; i++) {
    int u;
    cin>>u;
    festivals.push_back(u);
  }
  for (int i = 0; i < q; i++) {
    int u, v;
    cin>>u>>v;
    queries.push_back({u, v});
  }
  vector<pip> e = dij(edges);
  sort(all(e), comp);
  lr.resize(q, {0, m});
  while (1) {
    for (int i = 1; i <= n; i++) p[i] = i;
    vector<int> g[202020];

    bool flag = false;
    for (int i = 0; i < q; i++) {
      auto [l, r] = lr[i];
      if (l < r) {
        flag = true;
        g[(l+r)>>1].push_back(i);
      }
    }
    if (!flag) break;

    for (int i = 0; i < m; i++) {
      auto [w, uv] = e[i];
      auto [eu, ev] = uv;
      merge(eu, ev);
      for (auto j : g[i]) {
        auto [u, v] = queries[j];
        if (find(u) == find(v)) lr[j].se = i;
        else lr[j].fi = i+1; 
      }
    }
  }
  for (auto [l, r] : lr) cout << e[l].fi << "\n";
  return 0;
}
