#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int n, q;
vector<vector<int>> adj;
vector<int> s, e;
vector<ll> tree, lazy;

int idx = 1;
void traverse(int u) {
  s[u] = idx;
  for (auto v : adj[u]) {
    idx++;
    traverse(v); 
  }
  e[u] = idx;
}

void propagate(int node, int l, int r) {
  if (lazy[node] == 0) return;
  tree[node] += (r-l+1)*lazy[node];
  if (l != r) {
    tree[node*2] += lazy[node];
    tree[node*2+1] += lazy[node];
  }
  lazy[node] = 0;
}

void update(int node, int l, int r, int nl, int nr, ll v) {
  propagate(node, l, r);
  if (l > nr || nl > r) return;
  if (nl <= l && r <= nr) {
    tree[node] += (r-l+1)*v;
    if (l != r) {
      lazy[node*2] += v;
      lazy[node*2+1] += v;
    }
    return;
  }
  int m = (l+r)>>1;
  update(node*2, l, m, nl, nr, v);
  update(node*2+1, m+1, r, nl, nr, v);
  tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(int node, int l, int r, int k) {
  propagate(node, l, r);
  int m = (l+r)>>1;
  if (l == r) return tree[node];
  if (k <= m) return query(node*2, l, m, k);
  else return query(node*2+1, m+1, r, k);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>q; 
  adj.resize(n+1); s.resize(n+1); e.resize(n+1);
  tree.resize(4*n); lazy.resize(4*n);
  for (int i = 1; i <= n; i++) {
    int p; cin>>p;
    if (i == 1) continue;
    adj[p].push_back(i);
  }
  traverse(1);
  while (q--) {
    int qq; cin>>qq;
    if (qq == 1) {
      int k; ll v; cin>>k>>v;
      update(1, 1, n, s[k], e[k], v);
    } else {
      int k; cin>>k;
      cout<<query(1, 1, n, s[k])<<"\n";
    }
  }
}
