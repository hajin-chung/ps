#include <bits/stdc++.h>
#define N 1000
#define M 30000
#define INF 1000000000
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pip;

int n, m, k, s, e;
int d[N+5][N+5];
vector<vector<pii>> adj;

int main() {
  scanf("%d%d%d", &n, &m, &k);
  scanf("%d%d", &s, &e);
  adj.resize(n+1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  for (int i = 1; i <= n; i++) {
    if (i == s) continue;
    for (int j = 1; j <= n; j++)
      d[i][j] = INF;
  }

  priority_queue<pip, vector<pip>, greater<pip>> pq;
  pq.push({0, {s, 0}});
  while (!pq.empty()) {
    auto [dist, info] = pq.top(); pq.pop();
    auto [curr, ecnt] = info;
    if (ecnt > n) continue;
    if (dist > d[curr][ecnt]) continue;
    for (auto [next, w] : adj[curr]) {
      if (d[next][ecnt+1] > d[curr][ecnt] + w) {
        d[next][ecnt+1] = d[curr][ecnt] + w;
        pq.push({d[next][ecnt+1], {next, ecnt+1}});
      }
    }
  }

  int sum = 0, t = 0;
  for (int j = 0; j <= k; j++) {
    if (j != 0) scanf("%d", &t);
    sum += t;
    int ans = INF;
    for (int i = 1; i <= n; i++)
      ans = min(ans, d[e][i] + i * sum);
    printf("%d\n", ans);
  }
}
