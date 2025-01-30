#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppp;
const int MAX = 100000;
const int OFFSET = 50000;
int seg[4*MAX+5], cnt[4*MAX+5];

void update(int node, int l, int r, int ql, int qr, int val) {
  if (r < ql || qr < l) return;
  if (ql <= l && r <= qr) {
    cnt[node] += val;
  } else {
    int m = (l+r)>>1;
    update(node*2, l, m, ql, qr, val);
    update(node*2+1, m+1, r, ql, qr, val);
  }
  if (cnt[node]) seg[node] = r-l+1;
  else {
    if (l == r) seg[node] = 0;
    else seg[node] = seg[node*2]+seg[node*2+1];
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<ppp> a(2*n);
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    a[i] = {{x1, 1}, {y1+OFFSET, y2+OFFSET}};
    a[i+n] = {{x2, -1}, {y1+OFFSET, y2+OFFSET}};
  }
  sort(a.begin(), a.end());
  ll lx = a[0].fi.fi, ans = 0;
  for (int i = 0; i < 2*n; i++) {
    auto [xv, yy] = a[i];
    auto [x, v] = xv;
    auto [y1, y2] = yy;
    ans += (x-lx)*seg[1];
    update(1, 0, MAX, y1, y2-1, v);
    lx = x;
  }
  cout<<ans<<"\n";
}
