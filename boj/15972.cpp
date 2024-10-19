#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

typedef pair<int, int> pii;
typedef long long int ll;
vector<vector<pii>> adj;
vector<int> d;
queue<int> Q;

int main() {
  int n, m, h;
  scanf("%d %d %d", &n, &m, &h);
  adj.resize(n*m+1);
  d.resize(n*m+1);
  for (int i = 0; i < n+1; i++)
    for (int j = 0; j < m; j++) {
      int x, u, v; 
      scanf("%d", &x);
      if (x == -1) continue;
      if (i == 0) u = 0;
      else u = m*(i-1) + j + 1;
      if (i == n) v = 0;
      else v = m*i + j + 1;
      if (v != 0) adj[u].push_back({v, x});
      if (u != 0) adj[v].push_back({u, x});
    }
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < m+1; j++) {
      int x, u, v;
      scanf("%d", &x);
      if (x == -1) continue;
      if (j == 0) u = 0;
      else u = i*m + j;
      if (j == m) v = 0;
      else v = i*m + j + 1;
      if (v != 0) adj[u].push_back({v, x});
      if (u != 0) adj[v].push_back({u, x});
    }

  for (int i = 1; i <= n*m; i++) d[i] = INF;

  Q.push(0);
  d[0] = 0;
  while (!Q.empty()) {
    int curr = Q.front(); Q.pop();
    for (auto [next, w] : adj[curr])
      if (d[next] > max(w, d[curr])) {
        d[next] = max(w, d[curr]);
        Q.push(next);
      }
  }
  ll sum = 0;
  for (int i = 1; i <= n*m; i++) sum += (ll)d[i];
  printf("%lld\n", sum);
}
