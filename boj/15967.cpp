#include <bits/stdc++.h>
#define N 1000000
using namespace std;

typedef long long int ll;
int tree[4*N+5], lazy[4*N+1];
int q1, q2;
ll n;

void propagate(int node, ll l, ll r) {
  if (lazy[node] != 0) {
    tree[node] += (ll)(r-l+1)*lazy[node];
    if (l != r) {
      lazy[node*2] += lazy[node];
      lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
  }
}

void update(int node, ll l, ll r, ll ql, ll qr, ll diff) {
  propagate(node, l, r);
  if (r < ql || qr < l) return;
  if (ql <= l && r <= qr) {
    tree[node] += (ll)(r-l+1) * diff;
    if (l != r) {
      lazy[node*2] += diff;
      lazy[node*2+1] += diff;
    }
    return;
  }
  ll mid = (l+r)>>1;
  update(node*2, l, mid, ql, qr, diff);
  update(node*2+1, mid+1, r, ql, qr, diff);
  tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(int node, ll l, ll r, ll ql, ll qr) {
  propagate(node, l, r);
  if (r < ql || qr < l) return 0;
  if (ql <= l && r <= qr) return tree[node];
  ll mid = (l+r)>>1;
  ll lq = query(node*2, l, mid, ql, qr);
  ll rq = query(node*2+1, mid+1, r, ql, qr);
  return lq + rq;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> q1 >> q2;
  int m = q1+q2;
  for (int i = 1; i <= n; i++) {
    ll x; 
    cin >> x;
    update(1, 1, n, i, i, x);
  }

  while (m--) {
    ll q, l, r; 
    cin >> q >> l >> r;
    if (q == 1) cout << query(1, 1, n, l, r) << "\n";
    else {
      ll x;
      cin >> x;
      update(1, 1, n, l, r, x);
    }
  }
}
