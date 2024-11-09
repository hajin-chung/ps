#include <bits/stdc++.h>
#define fi first
#define se second
#define N 100000
#define MOD 1000000007
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
int n;
vector<ll> tree;
vector<pll> lazy;

void propagate(int node, int l, int r) {
  if (lazy[node].fi == 1 && lazy[node].se == 0) return;
  tree[node] *= lazy[node].fi;
  tree[node] += (r-l+1)*lazy[node].se;
  tree[node] %= MOD;
  if (l != r)
    for (int i = node*2; i <= node*2+1; i++) {
      lazy[i].fi *= lazy[node].fi; lazy[i].fi %= MOD;
      lazy[i].se = lazy[i].se*lazy[node].fi+lazy[node].se; lazy[i].se %= MOD;
    }
  lazy[node] = {1, 0};
}

void update(int node, int l, int r, int ql, int qr, pll k) {
  propagate(node, l, r);
  if (qr < l || r < ql) return;
  if (ql <= l && r <= qr) {
    tree[node] *= k.fi;
    tree[node] += (r-l+1)*k.se;
    tree[node] %= MOD;
    if (l != r)
      for (int i = node*2; i <= node*2+1; i++) {
        lazy[i].fi *= k.fi; lazy[i].fi %= MOD;
        lazy[i].se = lazy[i].se*k.fi+k.se; lazy[i].se %= MOD;
      }
    return;
  }
  int m = (l+r)>>1;
  update(node*2, l, m, ql, qr, k);
  update(node*2+1, m+1, r, ql, qr, k);
  tree[node] = tree[node*2]+tree[node*2+1];
  tree[node] %= MOD;
}

ll query(int node, int l, int r, int ql, int qr) {
  propagate(node, l, r);
  if (qr < l || r < ql) return 0;
  if (ql <= l && r <= qr) return tree[node];
  int m = (l+r)>>1;
  ll sum = query(node*2, l, m, ql, qr) + query(node*2+1, m+1, r, ql, qr);
  return sum % MOD;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n; tree.resize(4*n); lazy.resize(4*n, {1, 0});
  for (int x, i = 1; i <= n; i++) {
    cin>>x;
    update(1, 1, n, i, i, {0, x});
  }
  int m;
  cin>>m;
  while (m--) {
    int q, x, y;
    ll v;
    cin>>q>>x>>y;
    if (q != 4) cin>>v;
    if (q == 1) update(1, 1, n, x, y, {1, v});
    else if (q == 2) update(1, 1, n, x, y, {v, 0});
    else if (q == 3) update(1, 1, n, x, y, {0, v});
    else if (q == 4) cout << query(1, 1, n, x, y) << "\n";
  }
}
