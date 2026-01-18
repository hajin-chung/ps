#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 200000;
int bit[N+1];
struct J { int x, y, c; };

void f() {
  int n, k; cin>>n>>k;
  vector<int> xs(n);
  vector<set<int>> cx(k);
  vector<J> a(n);
  memset(bit, 0, sizeof(bit));
  for (int i = 0; i < n; i++) {
    int x, y, c; cin>>x>>y>>c; c--;
    a[i] = {x, y, c};
    xs[i] = x;
  }
  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());
  for (int i = 0; i < n; i++)
    a[i].x = lower_bound(all(xs), a[i].x) - xs.begin()+1;
  sort(all(a), [](J &u, J &v) {
    if (u.y != v.y) return u.y < v.y;
    return u.x < v.x;
  });
  auto query = [](int i) {
    int ret = 0;
    for (; i > 0; i -= i&-i) ret += bit[i];
    return ret;
  };
  auto update = [&](int i, int v) { 
    for (; i <= xs.size(); i+=i&-i) bit[i]+=v; };
  for (int i = 0; i < k; i++) { cx[i].insert(0); cx[i].insert(xs.size()+1); }
  int ans = 0, i, j;
  for (i = 0; i < n;) {
    for (j = i; j < n && a[j].y == a[i].y; j++) {
      auto it = cx[a[j].c].lower_bound(a[j].x);
      int r = *it, l = *(--it);
      ans = max(ans, query(r-1)-query(l));
    }
    for (; i < j; i++) {
      cx[a[i].c].insert(a[i].x);
      update(a[i].x, 1);
    }
  }
  for (auto c : cx) {
    int l = 0;
    c.erase(c.begin());
    for (auto it = c.begin(); it != c.end(); it++) {
      int r = *it;
      ans = max(ans, query(r-1)-query(l));
      l = r;
    }
  }
  cout<<ans<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) f();
}
