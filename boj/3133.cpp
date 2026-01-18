#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<int, pil> pip;
const int N = 300000;
const int MOD = 1e9+7;
struct T { 
  int x, y, idx; 
  bool operator<(T &t) {
    if (x == t.x) return y < t.y;
    return x < t.x;
  }
};
pil seg[4*N+5];

pil merge(pil a, pil b) {
  if (a.fi == b.fi) return {a.fi, (a.se+b.se)%MOD};
  else if (a.fi > b.fi) return a;
  else return b;
}

void update(int node, int l, int r, int idx, pil v) {
  if (idx < l || r < idx) return;
  if (idx == l && l == r) {
    if (seg[node].fi == v.fi) seg[node].se = (seg[node].se+v.se)%MOD;
    else if (seg[node].fi < v.fi) seg[node] = v;
    return;
  }
  int m = (l+r)>>1;
  update(node*2, l, m, idx, v);
  update(node*2+1, m+1, r, idx, v);
  seg[node] = merge(seg[node*2], seg[node*2+1]);
}

pil query(int node, int l, int r, int ql, int qr) {
  if (r < ql || qr < l) return {0, 1};
  if (ql <= l && r <= qr) return seg[node];
  int m = (l+r)>>1;
  pil rl = query(node*2, l, m, ql, qr);
  pil rr = query(node*2+1, m+1, r, ql, qr);
  return merge(rl, rr);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<T> a(n);
  vector<int> v;
  for (auto &[x, y, idx] : a) {
    cin>>x>>y;
    v.push_back(y);
  }
  sort(all(v)); v.erase(unique(all(v)), v.end());
  for (auto &[x, y, idx] : a) y = lower_bound(all(v), y)-v.begin()+1;
  sort(all(a), [](T &u, T &v) { return u.y < v.y; });
  for (int i = 0; i < n; i++) a[i].idx = i+1;
  sort(all(a));
  vector<pip> ups;
  int mx = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    auto [x, y, idx] = a[i];
    pil r = query(1, 1, n, 1, y-1); 
    if (r.fi == 0) r.se = 1;
    r.fi++;
    if (r.fi > mx) { mx = r.fi; cnt = r.se; }
    else if (r.fi == mx) { cnt = (cnt+r.se)%MOD; }
    ups.push_back({y, r});
    if (i+1<n && a[i+1].x != a[i].x) {
      for (auto [y, r] : ups)
        update(1, 1, n, y, r);
      ups.clear();
    }
  }
  cout<<mx<<"\n"<<cnt<<"\n";
}
