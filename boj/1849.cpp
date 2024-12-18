#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int n;
vector<ll> a, tree, lazy;

void init(int node, int l, int r) {
  if (l == r) {
    tree[node] = (ll)l;
    return;
  }
  int m = (l+r)>>1;
  init(node*2, l, m);
  init(node*2+1, m+1, r);
  tree[node] = tree[node*2] + tree[node*2+1];
}

void propagate(int node, int l, int r) {
  if (lazy[node] == 0) return;
  tree[node] += (r-l+1)*lazy[node];
  if (l != r) {
    lazy[node*2] += lazy[node];
    lazy[node*2+1] += lazy[node];
  }
  lazy[node] = 0;
}

void update(int node, int l, int r, int nl, int nr) {
  propagate(node, l, r);
  if (nr < l || nl > r) return;
  if (nl <= l && r <= nr) {
    tree[node] -= (r-l+1);
    if (l != r) {
      lazy[node*2]--;
      lazy[node*2+1]--;
    }
    return;
  }
  int m = (l+r)>>1;
  update(node*2, l, m, nl, nr);
  update(node*2+1, m+1, r, nl, nr);
  tree[node] = tree[node*2]+tree[node*2+1];
}

ll query(int node, int l, int r, int idx) {
  propagate(node, l, r);
  int m = (l+r)>>1;
  if (l == r) return tree[node];
  if (idx <= m) return query(node*2, l, m, idx);
  else return query(node*2+1, m+1, r, idx);
}

int find(int k) {
  int l = 1, r = n;
  while (l < r) {
    int m = (l+r)>>1;
    int v = query(1, 1, n, m);
    if (v > k) r = m;
    else l = m+1;
  }
  return l;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n; a.resize(n+1); tree.resize(4*n+1); lazy.resize(4*n+1);
  for (int i = 1; i <= n; i++) cin>>a[i];
  init(1, 1, n);
  vector<int> ans(n+1);
  for (int i = 1; i <= n; i++) {
    int idx = find(a[i]); 
    ans[idx] = i;
    update(1, 1, n, idx, n);
  }
  for (int i = 1; i <= n; i++) cout<<ans[i]<<"\n";
}
