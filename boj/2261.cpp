#include <bits/stdc++.h>
#define fi first
#define se second
#define MAX 10000
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef pair<int, int> pii;
vector<pii> a;
int n;

int pow2(int x) { return x * x; }
int dist(pii x, pii y) { return pow2(x.fi-y.fi) + pow2(x.se-y.se); }
int min3(int x, int y, int z) { return min(x, min(y, z)); }

bool comp(pii a, pii b) {
  if (a.se == b.se) return a.fi < b.fi;
  return a.se < b.se;
}

int rec(int s, int e) {
  if (e-s == 3) 
    return min3(dist(a[s], a[s+1]), dist(a[s+2], a[s+1]), dist(a[s], a[s+2]));
  if (e-s == 2)
    return dist(a[s], a[s+1]);
  
  int mid = (s+e)>>1;
  int d1 = rec(s, mid);
  int d2 = rec(mid, e);
  int mind = min(d1, d2);
  vector<pii> tmp;
  copy(a.begin()+s, a.begin()+e, back_inserter(tmp));
  sort(all(tmp), comp);
  auto lb = lower_bound(all(a), make_pair(a[mid].fi-mind, -MAX));
  auto ub = upper_bound(all(a), make_pair(a[mid].fi+mind, -MAX));
  for (auto it = lb; it != ub; it++) {
    const auto lbp = make_pair(-MAX, it->se-mind);
    const auto ubp = make_pair(-MAX, it->se+mind);
    auto ylb = lower_bound(all(tmp), lbp, comp);
    auto yub = upper_bound(all(tmp), ubp, comp);
    for (auto jt = ylb; jt != yub; jt++) 
      if (*it != *jt) {
        mind = min(mind, dist(*it, *jt));
        cout << dist(*it, *jt) << " ";
      }
  }
  return mind;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n; a.resize(n);
  for (auto &[x, y] : a) cin >> x >> y;
  sort(all(a));
  cout << rec(0, n) << "\n";
}
