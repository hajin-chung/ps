#include <bits/stdc++.h>
using namespace std;

const int N = 250000;
int a[N+5], seg[4*N+5][10], lazy[4*N+5];

void init(int node, int l, int r) {
  if (l == r) {
    seg[node][a[l]] = 1;
    return;
  }
  int m = (l+r)>>1;
  init(node*2, l, m); init(node*2+1, m+1, r);
  for (int i = 0; i < 10; i++)
    seg[node][i] += seg[node*2][i]+seg[node*2+1][i];
}

void propagate(int node, int l, int r) {
  if (!lazy[node]) return;
  int tmp[10];
  for (int i = 0; i < 10; i++)
    tmp[(i+lazy[node])%10] = seg[node][i];
  for (int i = 0; i < 10; i++)
    seg[node][i] = tmp[i];
  if (l != r) {
    lazy[node*2] += lazy[node];
    lazy[node*2+1] += lazy[node];
  }
  lazy[node] = 0;
}

void update(int node, int l, int r, int ql, int qr) {
  propagate(node, l, r);
  if (r < ql || qr < l) return;
  if (ql <= l && r <= qr) {
    lazy[node]++;
    propagate(node, l, r);
    return;
  }
  int m = (l+r)>>1;
  update(node*2, l, m, ql, qr);
  update(node*2+1, m+1, r, ql, qr);
  for (int i = 0; i < 10; i++)
    seg[node][i] = seg[node*2][i] + seg[node*2+1][i];
}

int query(int node, int l, int r, int ql, int qr) {
  propagate(node, l, r);
  if (r < ql || qr < l) return 0;
  if (ql <= l && r <= qr) {
    int sum = 0;
    for (int i = 0; i < 10; i++)
      sum += i*seg[node][i];
    return sum;
  }
  int m = (l+r)>>1;
  int rl = query(node*2, l, m, ql, qr);
  int rr = query(node*2+1, m+1, r, ql, qr);
  return rl+rr;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin>>n>>m;
  for (int i = 1; i <= n; i++) {
    char c; cin>>c;
    a[i] = c-'0';
  }
  init(1, 1, n);
  while (m--) {
    int ql, qr; cin>>ql>>qr;
    cout<<query(1, 1, n, ql, qr)<<"\n";
    update(1, 1, n, ql, qr);
  }
}
