#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int n, m, id;
vector<vector<int>> adj, scc;
vector<int> d;
vector<bool> finished;
stack<int> s;

int dfs(int curr) {
  d[curr] = ++id; 
  s.push(curr); 

  int parent = d[curr];
  for (auto next : adj[curr]) {
    if (d[next] == 0) parent = min(parent, dfs(next));
    else if (!finished[next]) parent = min(parent, d[next]);
  }

  if (parent == d[curr]) {
    vector<int> cc;
    while (1) {
      int t = s.top(); s.pop();
      cc.push_back(t);
      finished[t] = true;
      if (t == curr) break;
    }
    scc.push_back(cc);
  }
  return parent;
}

int main() {
  scanf("%d %d", &n, &m);
  adj.resize(n+1);
  d.resize(n+1);
  finished.resize(n+1);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) 
    if (d[i] == 0)
      dfs(i);
  printf("%d\n", scc.size());
  for (auto cc : scc) {
    sort(cc.begin(), cc.end());
    for (auto v : cc) printf("%d ", v);
    printf("-1\n");
  }
}
