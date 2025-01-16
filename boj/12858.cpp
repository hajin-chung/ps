#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int N = 100000;
int n;
ll bit[N+5], seg[4*N+5], a[N+5];

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

ll sum(int i) {
  ll ret = 0;
  while (i > 0) {
    ret += bit[i];
    i -= i&-i;
  }
  return ret;
}

void update(int i, ll v) {
  while (i <= n) {
    bit[i] += v;
    i += i&-i;
  }
}
void update(int node, int l, int r, int idx, ll v) {
  if (idx < l || idx > r) return;
  if (l == r) { seg[node] = v; return; }
  int m = (l+r)>>1;
  update(node*2, l, m, idx, v);
  update(node*2+1, m+1, r, idx, v);
  seg[node] = gcd(seg[node*2], seg[node*2+1]);
}
void update(int s, int e, ll v) {
  update(s, v); update(e+1, -v);
  ll ns = sum(s), ne = sum(e);
  update(1, 1, n, s, abs(ns));
  update(1, 1, n, e, abs(ne));
}

ll query(int node, int l, int r, int s, int e) {
  if (r < s || e < l) return -1;
  if (s <= l && r <= e) return seg[node];
  int m = (l+r)>>1;
  ll ql = query(node*2, l, m, s, e);
  ll qr = query(node*2+1, m+1, r, s, e);
  ll ret = 0;
  if (ql != -1 && qr != -1) ret = gcd(ql, qr);
  else if (ql != -1) ret = ql;
  else if (qr != -1) ret = qr;
  return ret;
}
ll query(int s, int e) { return query(1, 1, n, s, e); }

int main() {
  ios::sync_with_stdio(0); cin.tie(0);  
  cin>>n;
  for (int i = 1; i <= n; i++) {
    cin>>a[i];
    update(i, i, a[i]);
  }
  int q; cin>>q;
  while (q--) {
    ll t; int s, e; cin>>t>>s>>e;
    if (t == 0) cout<<query(s, e)<<"\n";
    else update(s, e, t);
  }
}

/*
 * gcd(a, b, ..) = gcd(a, |b-a|, |c-b|, |d-c|, ...)
 * bit: sum over a1-0, a2-a1, a3-a2, ...
 * => b1 +..+b3 = a3
 * seg: gcd seg |b1|, ... |bn|
 * on update: bit update a_s + v, a_e+1 - v
 * seg update |b_s|, |b_e+1|
* */
