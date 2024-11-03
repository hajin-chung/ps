#include <bits/stdc++.h>
#define N 100000
using namespace std;

int n, m;
int tree[4*N+5], lazy[4*N+5];

void propagate(int node, int l, int r) {
  lazy[node] %= 2;
  if (lazy[node] == 1) {
    tree[node] = (r-l+1) - tree[node];
    if (l != r) {
      tree[node*2]++;
      tree[node*2+1]++;
    }
    tree[node] = 0;
  } 
}

void update(int node, int l, int r, int ql, int qr) {
  /*cout << "update: " << node << " " << l << " "  << r << " " << ql << " " << qr << "\n";*/
  propagate(node, l, r);
  if (r < ql || qr < l) return; 
  if (ql <= l && r <= qr) {
    tree[node] = (r-l+1)-tree[node];
    if (l != r) {
      lazy[node*2]++;
      lazy[node*2+1]++;
    }
    return;
  }

  int mid = (l+r)>>1;
  update(node*2, l, mid, ql, qr);
  update(node*2+1, mid+1, r, ql, qr);
  tree[node] = tree[node*2]+tree[node*2+1];
}

int query(int node, int l, int r, int ql, int qr) {
  propagate(node, l, r);
  if (r < ql || qr < l) return 0; 
  if (ql <= l && r <= qr) return tree[node];
  int mid = (l+r)>>1;
  int ls = query(node*2, l, mid, ql, qr); 
  int rs = query(node*2+1, mid+1, r, ql, qr);
  return ls + rs;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  while (m--) {
    int q, l, r;
    cin >> q >> l >> r;
    if (q == 0) update(1, 1, n, l, r);
    else cout << query(1, 1, n, l, r) << "\n";
    for (int i = 1; i <= n; i++) cout << query(1, 1, n, i, i) << " ";
    cout << "\n";
  }
}
