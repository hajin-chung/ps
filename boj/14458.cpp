#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int N = 100000;
const ll INF = 1e9;
ll seg1[4*N+5], seg2[4*N+5], lazy[4*N+5];

void update(int node, int l, int r, int i) {
  if (i < l || r < i) return; 
  if (l == r && r == i) {
    seg1[node] = 1;
    return;
  }
  int m = (l+r)>>1;
  update(node*2, l, m, i);
  update(node*2+1, m+1, r, i);
  seg1[node] = seg1[node*2]+seg1[node*2+1];
}

ll query(int node, int l, int r, int i) {
  if (r < i) return 0;
  if (i <= l) return seg1[node];
  int m = (l+r)>>1;
  ll rl = query(node*2, l, m, i);
  ll rr = query(node*2+1, m+1, r, i);
  return rl + rr;
}

void propagate(int node, int l, int r) {
  if (!lazy[node]) return;
  seg2[node] += lazy[node]*(r-l+1);
  if (l != r) {
    lazy[node*2] += lazy[node];
    lazy[node*2+1] += lazy[node];
  }
  lazy[node] = 0;
}

void update(int node, int l, int r, int ql, int qr, ll v) {
  propagate(node, l, r);
  if (r < ql || qr < l) return;
  if (ql <= l && r <= qr) {
    lazy[node] += v;
    propagate(node, l, r);
    return;
  }
  int m = (l+r)>>1;
  update(node*2, l, m, ql, qr, v);
  update(node*2+1, m+1, r, ql, qr, v);
  seg2[node] = seg2[node*2]+seg2[node*2+1];
}

ll query() {
  propagate(1, 1, 10);
  return seg2[1];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<int> a(n+1), idx(n+1);
  for (int i = 1; i <= n; i++) {
    int x; cin>>x;
    idx[x] = i;
  }
  for (int i = 1; i <= n; i++) {
    int x; cin>>x;
    a[idx[x]] = i;
  }
  for (int i = 1; i <= n; i++) {
    update(1, 1, n, a[i]);
    if (a[i] != n) {
      int r = query(1, 1, n, a[i]+1);
      update(1, 1, n, a[i], a[i], r);
    }
  }
  ll ans = INF;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, query());
    if (a[i] != 1) update(1, 1, n, 1, a[i]-1, -1);
    if (a[i] != n) update(1, 1, n, a[i], a[i], n-a[i]);
  }
  cout<<ans<<"\n";
}
