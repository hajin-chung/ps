#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<ll> tree, lazy;
int n, m, k;

void propagate(int node, int l, int r) {
  if (lazy[node] != 0) {
    tree[node] += (r-l+1)*lazy[node];
    if (l != r) {
      lazy[node*2] += lazy[node];
      lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
  }
}

void update(int node, int l, int r, int ql, int qr, int diff) {
  propagate(node, l, r); 
  if (r < ql || qr < l) return;
  if (ql <= l && r <= qr) {
    tree[node] += (l-r+1)*diff;
    if (l != r) {
      lazy[node*2] += diff;
      lazy[node*2+1] += diff;
    }
    return;
  }
  int mid = (l+r)>>1;
  update(node*2, l, mid, ql, qr, diff);
  update(node*2+1, mid+1, r, ql, qr, diff);
  tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(int node, int l, int r, int ql, int qr) {
  propagate(node, l, r);
  if (r < ql || qr < l) return 0;
  if (ql <= l && r <= qr) return tree[node];
  int mid = (l+r)>>1;
  return query(node*2, l, mid, ql, qr) + query(node*2+1, mid+1, r, ql, qr);
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  tree.resize(4*n+5);
  lazy.resize(4*n+5);
  for (int i = 1; i <= n; i++) {
    ll x;
    scanf("%lld", &x);
    update(1, 1, n, i, i, x);
  }
  for (int i = 0; i < m+k; i++) {
    int q;
    scanf("%d", &q);
    if (q == 1) {
      int l, r;
      ll diff;
      scanf("%d%d%lld", &l, &r, &diff);
      update(1, 1, n, l, r, diff);
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%lld\n", query(1, 1, n, l, r));
    }
  }
}
