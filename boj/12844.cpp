#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> tree, lazy;

void propagate(int node, int l, int r) {
  if (lazy[node] == 0) return;
  if ((r-l+1)%2 == 1) tree[node] ^= lazy[node];
  if (l != r) {
    lazy[node*2] ^= lazy[node];
    lazy[node*2+1] ^= lazy[node];
  }
  lazy[node] = 0;
}

void update(int node, int l, int r, int ql, int qr, int k) {
  propagate(node, l, r);
  if (qr < l || r < ql) return;
  if (ql <= l && r <= qr) {
    if ((r-l+1)%2 == 1) tree[node] ^= k;
    if (l != r) {
      lazy[node*2] ^= lazy[node];
      lazy[node*2+1] ^= lazy[node];
    }
    return;
  }
  int m = (l+r)>>1;
  update(node*2, l, m, ql, qr, k); 
  update(node*2+1, m+1, r, ql, qr, k); 
  tree[node] = tree[node*2]^tree[node*2+1];
}

int query(int node, int l, int r, int ql, int qr) {
  propagate(node, l, r);
  if (qr < l || r < ql) return 0;
  if (ql <= l && r <= qr) return tree[node];
  int m = (l+r)>>1;
  return query(node*2, l, m, ql, qr)^query(node*2+1, m+1, r, ql, qr);
}

void print(int node, int l, int r) {
  propagate(node, l, r);
  cout<<node<<"("<<l<<", "<<r<<"): "<<tree[node]<<"\n";
  if (l != r) {
    int m = (l+r)>>1;
    print(node*2, l, m);
    print(node*2+1, m+1, r);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n; tree.resize(4*n+1); lazy.resize(4*n+1);
  for (int x, i = 0; i < n; i++) {
    cin>>x; 
    update(1, 0, n-1, i, i, x);
  }
  print(1, 0, n-1);
  int m;
  cin>>m;
  while (m--) {
    int q, i, j, k;
    cin>>q>>i>>j;
    if (q == 2) cout<<query(1, 0, n-1, i, j)<<"\n";
    else {
      cin>>k;
      update(1, 0, n-1, i, j, k);
    }
  }
}
