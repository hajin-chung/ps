#include <bits/stdc++.h>
#define pb push_back 
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
int n, m;
vector<vector<pii>> edges;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); 
  cin>>n>>m;
  edges.resize(n+1);
  // si-s0 <= i <=> s0+i >= si
  for (int i = 1; i <= n; i++) edges[0].pb({i, i}); 
  for (int i = 1; i <= n; i++) {
    // s_i-1 <= s_i <= s_i-1 + 1
    edges[i-1].pb({i, 1});
    edges[i].pb({i-1, 0});
  }

  for (int i = 0; i < m; i++) {
    int l, r, w;
    cin>>l>>r>>w;
    edges[r].pb({l-1, -w});
    edges[l-1].pb({r, w});
  }

  bool negcycle = false;
  vector<int> dist(n+1, 1e9);
  dist[0] = 0;
  for (int iter = 0; iter <= n+1; iter++) {
    for (int u = 0; u <=n ; u++)
      for (auto [v, w] : edges[u]) {
        if (dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          if (iter == n+1) negcycle = true;
        }
      }
  }

  if (negcycle) {
    cout << "NONE\n"; 
    return 0;
  }

  for (int i = 1; i <= n; i++) {
    if (dist[i] - dist[i-1]) cout << "#";
    else cout << "-";
  }
  cout << "\n";
}
