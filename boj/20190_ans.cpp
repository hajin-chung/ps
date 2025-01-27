#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
const int N = 300000;
const ll INF = 1e9;
int n;
int a[N+1];
ll bit[N+1], seg[4*N+5], lazy[4*N+5];

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

void propagate(int node, int l, int r) {
  if (lazy[node] == 0) return;
  seg[node] += lazy[node];
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
    seg[node] += v;
    if (l != r) {
      lazy[node*2] += v;
      lazy[node*2+1] += v;
    }
    return;
  }
  int m = (l+r)>>1;
  update(node*2, l, m, ql, qr, v);
  update(node*2+1, m+1, r, ql, qr, v);
  seg[node] = min(seg[node*2], seg[node*2+1]);
}

ll query(int node, int l, int r, int ql, int qr) {
  propagate(node, l, r);
  if (r < ql || qr < l) return INF;
  if (ql <= l && r <= qr) return seg[node];
  int m = (l+r)>>1;
  ll rl = query(node*2, l, m, ql, qr);
  ll rr = query(node*2+1, m+1, r, ql, qr);
  return min(rl, rr);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); 
  cin>>n;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    cin>>a[i];
    v.push_back(a[i]);
  }
  sort(all(v));
  v.erase(unique(all(v)), v.end());
  for (int i = 1; i <= n; i++)
    a[i] = lower_bound(all(v), a[i])-v.begin()+1;
  ll cnt = 0;
  for (int i = n; i >= 1; i--) {
    cnt += sum(a[i]-1);
    update(a[i], 1);
  }
  for (int i = 1; i <= n; i++)
    update(1, 0, n+1, a[i]+1, n+1, 1);
  for (int i = 1; i <= n; i++) {
    update(1, 0, n+1, a[i]+1, n+1, -1);
    ll l = query(1, 0, n+1, a[i], a[i]);
    ll r = query(1, 0, n+1, 0, n+1);
    cout<<cnt-l+r<<" ";
    update(1, 0, n+1, 0, a[i]-1, 1);
  }
  cout<<"\n";
}
