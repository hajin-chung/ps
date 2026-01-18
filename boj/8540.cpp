#include <bits/stdc++.h>
#include <functional>
#include <vector>
#define INF 1000000000
using namespace std;

typedef pair<int, int> pii;
vector<vector<int>> adj;
vector<int> order, lookup;
int a, n, b, k, m, e, s;
int ans = INF;

int isen(int v) {
  return (a < v && v <= a+n) ? 1 : 0;
}

// curr -> curr + 1 withouth touching order[i] where i > idx + 1
int dij(int idx) {
  vector<int> d(e+1, INF);
  priority_queue<pii, vector<pii>, greater<pii>> pq;

  d[order[idx]] = 0;
  pq.push({0, order[idx]});
  while (!pq.empty()) {
    auto [dist, curr] = pq.top(); pq.pop();
    if (dist > d[curr]) continue;
    for (auto next : adj[curr]) {
      if (lookup[next] <= idx+1 && d[next] > d[curr] + isen(next)) {
        d[next] = d[curr] + isen(next);
        pq.push({d[next], next});
      }
    }
  }
  return d[order[idx+1]];
}

int main() {
  scanf("%d%d%d%d%d",&a,&n,&b,&k,&m);
  s = 0, e = a+n+b+1;
  adj.resize(e+1);
  lookup.resize(e+1);
  order.push_back(0);
  for (int i=0;i<k;i++) {
    int x;
    scanf("%d",&x);
    order.push_back(x);
    lookup[x] = i+1;
  }
  order.push_back(a+n+b+1);
  for (int i=0;i<m;i++) {
    int u, v;
    scanf("%d%d",&u,&v);
    if (u > v) swap(u, v);
    if (u <= a+n && v > a) adj[u].push_back(v);
    if (v <= a+n && u > a) adj[v].push_back(u);
  }
  for (int i = 1; i <= a; i++) adj[s].push_back(i);
  for (int i = a+n+1; i <= a+n+b; i++) adj[i].push_back(e);

  int ans = 0;
  for (int i = 0; i <= k; i++) {
    int dist = dij(i);
    if (dist >= INF) {
      ans = INF;
      break;
    } else {
      ans += dist;
    }
  }

  printf("%d\n", ans >= INF ? -1 : ans);
}
