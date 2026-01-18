#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pip;
int n;

int find(int u, vector<int>& p) {
  if (p[u] == u) return u;
  return p[u] = find(p[u], p);
}

void merge(int u, int v, vector<int>& p) {
  u = find(u, p);
  v = find(v, p);
  if (u > v) swap(u, v);
  p[v] = u;
}

int mst(vector<pip>& e) {
  int ret = 0;
  vector<int> p(n+1);
  for (int i = 1; i <= n; i++) p[i] = i;
  priority_queue<pip, vector<pip>, greater<pip>> pq; 
  for (auto edge : e) pq.push(edge);
  while (!pq.empty()) {
    auto [w, uv] = pq.top(); pq.pop();
    auto [u, v] = uv;
    u = find(u, p);
    v = find(v, p);
    if (u == v) continue;
    merge(u, v, p); 
    ret += w;
  }
  return ret;
}

bool solve() {
  int m, k;
  cin >> n >> m >> k;
  if (n == 0 && m == 0 && k == 0) return false;
  char c;
  vector<pip> e;
  int u, v, w;
  for (int i = 0; i < m; i++) {
    cin >> c >> u >> v;
    if (c == 'B') w = 1;
    else w = 0;
    e.push_back({w, {u, v}});
    e.push_back({w, {v, u}});
  }

  int mn = mst(e);
  for (auto &[w, uv]: e) w = -w;
  int mx = -mst(e);
  int ans = mn <= k && k <= mx;
  cout << ans << "\n";
  return true;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  while(solve()) {}
}
