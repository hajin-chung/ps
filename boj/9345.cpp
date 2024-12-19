#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void init(vi &tree, int node, int l, int r, bool nx) {
  if (l == r) {
    tree[node] = l;
    return;
  } 
  int m = (l+r)>>1;
  init(tree, node*2, l, m, nx);
  init(tree, node*2+1, m+1, r, nx);
  tree[node] = 
    nx ? min(tree[node*2], tree[node*2+1]) : max(tree[node*2], tree[node*2+1]);
}

void update(vi &tree, int node, int l, int r, bool nx, int idx, int v) {
  if (idx < l || r < idx) return;
  if (l == r) {
    tree[node] = v;
    return;
  }
  int m = (l+r)>>1;
  if (idx <= m) update(tree, node*2, l, m, nx, idx, v);
  else update(tree, node*2+1, m+1, r, nx, idx, v);
  tree[node] = 
    nx ? min(tree[node*2], tree[node*2+1]) : max(tree[node*2], tree[node*2+1]);
}

int query(vi &tree, int node, int l, int r, int nl, int nr, bool nx) {
  if (nl > r || l > nr) return nx ? INT_MAX : INT_MIN;
  if (nl <= l && r <= nr) return tree[node];
  int m = (l+r)>>1;
  int lq = query(tree, node*2, l, m, nl, nr, nx);
  int rq = query(tree, node*2+1, m+1, r, nl, nr, nx);
  return nx ? min(lq, rq) : max(lq, rq);
}

void solve() {
  int n, k; cin>>n>>k;
  vi mnt(4*n), mxt(4*n), a(n+1);
  init(mnt, 1, 1, n, 1); init(mxt, 1, 1, n, 0);
  for (int i = 1; i <= n; i++) a[i] = i;
  while (k--) {
    int q, l, r; cin>>q>>l>>r;
    l++; r++;
    if (q == 0) {
      swap(a[l], a[r]);
      update(mnt, 1, 1, n, 1, l, a[l]);
      update(mnt, 1, 1, n, 1, r, a[r]);
      update(mxt, 1, 1, n, 0, l, a[l]);
      update(mxt, 1, 1, n, 0, r, a[r]);
    } else {
      int nq = query(mnt, 1, 1, n, l, r, 1);
      int xq = query(mxt, 1, 1, n, l, r, 0);
      if (nq == l && xq == r) cout<<"YES\n";
      else cout<<"NO\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) solve();
}
