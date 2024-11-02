#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define N 100000
using namespace std;

vector<int> tree[4*N+5];
int a[N+5];
int n, m;

void init(int node, int l, int r) {
  if (l == r) {
    tree[node].push_back(a[l]);
    return;
  }
  int mid = (l+r)>>1;
  init(node*2, l, mid);
  init(node*2+1, mid+1, r);
  merge(all(tree[node*2]), all(tree[node*2+1]), back_inserter(tree[node]));
}

int query(int node, int l, int r, int ql, int qr, int k) {
  if (r < ql || qr < l) return 0;
  if (ql <= l && r <= qr) 
    return tree[node].end() - upper_bound(all(tree[node]), k);
  int mid = (l+r)>>1;
  return query(node*2, l, mid, ql, qr, k) + query(node*2+1, mid+1, r, ql, qr, k);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  init(1, 1, n);
  scanf("%d", &m);
  while (m--) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    printf("%d\n", query(1, 1, n, l, r, k));
  }
}
