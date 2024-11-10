#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef pair<int, int> pii;

bool comp(pii a, pii b) {
  if (a.se == b.se) return a.fi < b.fi;
  else return a.se < b.se;
}

bool comp2(pii a, pii b) {
  if (a.fi == b.fi) return a.se > b.se;
  else return a.fi < b.fi;
}

struct Seg {
  int n, my;
  vector<pii> a;
  vector<int> tree;

  void update(int idx) {
    while (idx <= n) {
      tree[idx]++;
      idx += idx&-idx;
    }
  }

  int query(int idx) {
    int sum = 0;
    while (idx > 0) {
      sum += tree[idx];
      idx -= idx&-idx;
    }
    return sum;
  }
  int query(int l, int r) { return query(r) - query(l-1); }

  Seg(int N, vector<pii> &b) : n(N) {
    tree.resize(n+1);
    sort(all(b), comp);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      a.push_back(b[i]);
      if (i == 0 || b[i-1].se != b[i].se) a[i].se = ++cnt;
      else a[i].se = cnt;
    }
    my = cnt;
  }

  int solve() {
    int ret = 0;
    sort(all(a), comp2);
    for (auto [x, y] : a) {
      ret += query(y, my);
      update(y);
    }
    return ret;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin>>t;
  while (t--) {
    int n;
    vector<pii> b;
    cin>>n; b.resize(n);
    for (auto &[x, y] : b) cin>>x>>y;
    Seg *seg = new Seg(n, b);
    cout << seg->solve() << endl;
  }
}
