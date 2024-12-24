#include <bits/stdc++.h>
#define N 100000
using namespace std;

vector<int> adj[N+1];
int s[N+1], e[N+1];
int rbit[N+1], bit[N+1];
int cnt, n, m;

void traverse(int u) {
  s[u] = ++cnt;
  for (auto v : adj[u])
    traverse(v);
  e[u] = cnt;
}

void update(int *bit, int idx, int v) {
  while (idx < n) {
    bit[idx] += v;
    idx += idx&-idx; 
  }
}

// a[1] - a[0] -> bit[1]
void update(int l, int r, int w) {
  update(rbit, l, w);
  if (r != n) update(rbit, r+1, -w);
}

void update(int u, int w) {
  update(bit, u, w);
}

int query(int *bit, int idx) {
  int ret = 0;
  while (idx > 0) {
    ret += bit[idx];
    idx -= idx&-idx;
  }
  return ret;
}

int query(int l, int r) {
  return query(bit, r) - query(bit, l-1);
}

int query(int u) {
  return query(rbit, u);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>m;
  for (int i = 1; i <= n; i++) {
    int x; cin>>x;
    if (i != 1) adj[x].push_back(i);
  }
  traverse(1);
  int dir = 0;
  while (m--) {
    int q; cin>>q;
    if (q == 1) {
      int u, w; cin>>u>>w;
      if (dir == 0) update(s[u], e[u], w);
      else update(s[u], w);
    } else if (q == 2) {
      int u; cin>>u;
      cout<<query(s[u], e[u])+query(s[u])<<"\n";
    } else {
      dir = 1 - dir;
    }
  }
}
