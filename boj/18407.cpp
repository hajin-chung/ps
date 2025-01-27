#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef pair<int, int> pii;
const int N = 200000;
int seg[4*N+5], lazy[4*N+5];

void propagate(int node, int l, int r) {
  if (lazy[node] == 0) return;
  seg[node] = max(seg[node], lazy[node]);
  if (l != r) {
    lazy[node*2] = max(lazy[node*2], lazy[node]);
    lazy[node*2+1] = max(lazy[node*2+1], lazy[node]);
  }
  lazy[node] = 0;
}

void update(int node, int l, int r, int ql, int qr, int v) {
  propagate(node, l, r);
  if (r < ql || qr < l) return;
  if (ql <= l && r <= qr) {
    seg[node] = max(seg[node], v);
    if (l != r) {
      lazy[node*2] = max(lazy[node*2], v);
      lazy[node*2+1] = max(lazy[node*2+1], v);
    }
    return;
  }
  int m = (l+r)>>1;
  update(node*2, l, m, ql, qr, v);
  update(node*2+1, m+1, r, ql, qr, v);
}

int query(int node, int l, int r, int ql, int qr) {
  propagate(node, l, r);
  if (r < ql || qr < l) return 0;
  if (ql <= l && r <= qr) return seg[node]; 
  int m = (l+r)>>1;
  return max(query(node*2,l,m,ql,qr),query(node*2+1,m+1,r,ql,qr));
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<pii> a(n);
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int w, d; cin>>w>>d;
    a[i] = {d, d+w-1};
    v.push_back(d); v.push_back(d+w-1);
  }
  sort(all(v));
  v.erase(unique(all(v)), v.end());
  for (auto &[s, e] : a) {
    s = lower_bound(all(v), s)-v.begin()+1;
    e = lower_bound(all(v), e)-v.begin()+1;
    cout<<s<<" "<<e<<endl;
  }
  cout<<v.size()<<endl;
  int ans = 0;
  for (auto [s, e] : a) {
    int mx = query(1, 1, v.size(), s, e)+1;
    ans = max(ans, mx);
    cout<<v.size()<<" "<<s<<" "<<e<<" "<<mx<<"hi"<<endl;
    update(1, 1, v.size(), s, e, mx);
    cout<<mx<<endl;
  }
  cout<<ans<<"\n";
}
