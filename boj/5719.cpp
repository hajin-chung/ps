#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

typedef pair<int, int> pii;
int adj[505][505];
vector<vector<int>> path;
int n, m, s, e;

int dij() {
  vector<int> d;
  priority_queue<pii, vector<pii>, greater<pii>> pq; 

  d.resize(n, INF);
  path.resize(n);
  d[s] = 0;
  pq.push({0, s});
  while (!pq.empty()) {
    auto [dist, curr] = pq.top(); pq.pop();
    if (dist > d[curr]) continue;
    for (int next = 0; next < n; next++) {
      if (d[next] == d[curr] + adj[curr][next]) 
        path[next].push_back(curr);
      if (d[next] > d[curr] + adj[curr][next]) {
        path[next].resize(0);
        d[next] = d[curr] + adj[curr][next];
        path[next].push_back(curr); 
        pq.push({d[next], next});
      }
    }
  }
  return d[e];
}

void dfs(int curr) {
  for (auto next : path[curr]) {
    adj[next][curr] = INF;
    dfs(next);
  }
}

bool solve() {
  scanf("%d %d", &n, &m);
  if (n == 0 && m == 0) return false;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      adj[i][j] = INF;
  
  scanf("%d %d", &s, &e);
  for (int i = 0; i < m; i++) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    adj[a][b] = w;
  }

  dij();
  dfs(e);
  int mn = dij(); 
  if (mn == INF) printf("-1\n");
  else printf("%d\n", mn);
  return true;
}

int main() {
  while (solve()) {}
}
