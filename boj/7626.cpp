#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using namespace std;

const int MAX = 400000;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppp;
typedef long long int ll;
int seg[4*MAX+5], cnt[4*MAX+1];
vector<int> ys;

void update(int node, int l, int r, int ql, int qr, int v) {
  if (r < ql || qr < l) return;
  if (ql <= l && r <= qr) cnt[node] += v;
  else {
    int m = (l+r)>>1;
    update(node*2, l, m, ql, qr, v);
    update(node*2+1, m+1, r, ql, qr, v);
  }
  if (cnt[node]) {
    seg[node] = ys[r+1]-ys[l];
  } else {
    if (l == r) seg[node] = 0;
    else seg[node] = seg[node*2]+seg[node*2+1];
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<ppp> a(2*n);
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2; cin>>x1>>x2>>y1>>y2;
    ys.push_back(y1); ys.push_back(y2);
    a[i] = {{x1, 1}, {y1, y2}};
    a[i+n] = {{x2, -1}, {y1, y2}};
  }
  sort(all(ys));
  ys.erase(unique(all(ys)), ys.end());
  ys.push_back(ys.back());
  int range = ys.size() > 1 ? ys.size()-2:0;
  sort(all(a));
  for (auto &[xv, yy] : a) {
    auto &[y1, y2] = yy;
    y1 = upper_bound(all(ys), y1)-ys.begin()-1;
    y2 = upper_bound(all(ys), y2)-ys.begin()-1;
    y1 = max(0, y1);
    y2 = min(range, y2);
  }
  int lx = 0; ll ans = 0;
  for (int i = 0; i < 2*n; i++) {
    auto [xv, yy] = a[i];
    auto [x, v] = xv; auto [y1, y2] = yy;
    if (i) ans += (ll)(x-lx)*seg[1];
    update(1, 0, MAX, y1, y2-1, v);
    lx = x;
  }
  cout<<ans<<"\n";
}
