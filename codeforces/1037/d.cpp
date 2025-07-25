#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 1e5;
typedef pair<int, int> pii;
vector<int> l, r;
vector<pii> c;
int tree[4*N+5], lazy[4*N+5];

void propagate(int node, int l, int r) {
  if (lazy[node] == 0) return;
  tree[node] = max(tree[node], lazy[node]);
  if (l != r) {
    lazy[node*2] = max(lazy[node*2], lazy[node]);
    lazy[node*2+1] = max(lazy[node*2+1], lazy[node]);
  }
  lazy[node] = 0;
}

int query(int node, int l, int r, int ql, int qr) {
  propagate(node, l, r);
  if (r < ql || qr < l) return 0;
  if (ql <= l && r <= qr) return tree[node];
  int m = (l+r)>>1;
  int ll = query(node*2, l, m, ql, qr);
  int rr = query(node*2+1, m+1, r, ql, qr);
  return max(ll, rr);
}

void update(int node, int l, int r, int ql, int qr, int v) {
  propagate(node, l, r);
  if (r < ql || qr < l) return;
  if (ql <= l && r <= qr) {
    lazy[node] = max(lazy[node], v);
    propagate(node, l, r);
    return;
  }
  int m = (l+r)>>1;
  update(node*2, l, m, ql, qr, v);
  update(node*2+1, m+1, r, ql, qr, v);
  tree[node] = max(tree[node*2], tree[node*2+1]);
}

void f() {
  int n, k; cin>>n>>k;
  for (int i = 0; i < 4*n+5; i++) tree[i] = lazy[i] = 0;
  l.resize(0); r.resize(0); c.resize(0);
  vector<int> v;
  v.push_back(k);
  for (int i = 0; i < n; i++) {
    int ll, rr, cc;
    cin>>ll>>rr>>cc;
    l.push_back(ll);
    r.push_back(rr);
    c.push_back({cc, i});
    v.push_back(ll);
    v.push_back(rr);
    v.push_back(cc);
  }

  sort(all(v));
  v.erase(unique(all(v)), v.end());
  k = lower_bound(all(v), k)-v.begin();
  for (int i = 0; i < n; i++) {
    l[i] = lower_bound(all(v), l[i])-v.begin();
    r[i] = lower_bound(all(v), r[i])-v.begin();
    c[i].fi = lower_bound(all(v), c[i].fi)-v.begin();
  }

  // cout<<"============="<<"\n";
  // cout<<k<<"\n";
  // for (int i = 0; i < n; i++) cout<<l[i]<<" "<<r[i]<<" "<<c[i].fi<<"\n";
  // cout<<"============="<<"\n";
  
  int mx = v.size();
  sort(c.begin(), c.end(), greater<pii>());
  for (auto [cc, idx] : c) {
    int rr = query(1, 0, mx, cc, cc);
    // cout<<cc<<" "<<rr<<"\n";
    update(1, 0, mx, l[idx], r[idx], max(cc, rr));
  }
  // cout<<query(1, 0, mx, k, k)<<"\n";
  cout<<v[query(1, 0, mx, k, k)]<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) f();
}
