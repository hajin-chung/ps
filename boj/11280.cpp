#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> d;
vector<bool> finished;
vector<vector<int>> scc;
stack<int> s;
int n, m, cnt;

int dfs(int curr) {
  d[curr] = ++cnt;
  s.push(curr); 

  int ret = d[curr];
  for (auto next : adj[curr]) {
    if (d[next] == 0) ret = min(ret, dfs(next));
    else if (!finished[next]) ret = min(ret, d[next]);
  }

  if (ret == d[curr]) {
    vector<int> cc;
    while (1) {
      int t = s.top(); s.pop();
      cc.push_back(t);
      finished[t] = true;
      if (t == curr) break;
    }
    scc.push_back(cc);
  }
  return ret;
}

int main() {
  scanf("%d%d", &n, &m);
  adj.resize(2*n+1);
  d.resize(2*n+1);
  finished.resize(2*n+1);
  for (int i = 0; i < m; i++) {
    int u, v; 
    scanf("%d%d", &u, &v);
    if (u < 0) u = -u+n;
    if (v < 0) v = -v+n;
    adj[u].push_back(v>n ? v-n : v+n);
    adj[v].push_back(u>n ? u-n : u+n);
  }

  for (int i = 1; i <= 2*n; i++)
    if (d[i] == 0)
      dfs(i);

  for (auto cc : scc)  
    for (auto curr : cc)
      for (auto next : cc)
        if (abs(curr - next) == n) {
          printf("0\n");
          return 0;
        }
  printf("1\n");
  return 0;
}
