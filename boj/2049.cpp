#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
pll pivot;

int ccw(pll a, pll b, pll c) {
  ll v = (b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
  if (v > 0) return 1;
  if (v < 0) return -1;
  return 0;
}

ll dist(pll a, pll b) {
  ll dx = a.fi-b.fi; 
  ll dy = a.se-b.se; 
  return dx*dx+dy*dy;
}

bool comp(pll a, pll b) {
  int v = ccw(pivot, a, b); 
  if (v != 0) return v > 0;
  return dist(pivot, a) < dist(pivot, b);
}

pll operator+(const pll a, const pll b) { return {a.fi + b.fi, a.se + b.se}; }
pll operator-(const pll a, const pll b) { return {a.fi - b.fi, a.se - b.se}; }

void solve() {
  int n;
  vector<pll> a;
  cin >> n; a.resize(n);
  for (auto &[x, y] : a) cin >> x >> y;
  sort(all(a));
  pivot = a[0];
  sort(all(a), comp);
  vector<pll> hull;
  hull.push_back(a[0]); hull.push_back(a[1]);
  for (int i = 2; i < n; i++) {
    while (hull.size() >= 2) {
      pll second = hull.back(); hull.pop_back();
      pll first = hull.back();
      if (ccw(first, second, a[i]) > 0) {
        hull.push_back(second);
        break;
      }
    }
    hull.push_back(a[i]);
  }

  int r = 0;
  ll mx = 0;
  int p1, p2;
  a = hull;
  n = hull.size();
  for (int i = 0; i < n; i++) {
    while (r < n * 2 && ccw(a[i], a[(i+1)%n], a[(i+1)%n]+a[(r+1)%n]-a[r%n]) >= 0) {
      if (mx < dist(a[i], a[r%n])) {
        mx = dist(a[i], a[r%n]);
        p1 = i, p2 = r%n;
      }
      r++;
    }
    if (mx < dist(a[i], a[r%n])) {
      mx = dist(a[i], a[r%n]);
      p1 = i, p2 = r%n;
    }
  }
  cout<<mx<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
}
