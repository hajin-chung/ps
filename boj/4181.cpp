#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define INF 1000000000
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
pll pivot = {INF, INF};
int n;
vector<pll> a;

ll ccw(pll a, pll b, pll c) {
  ll v = (b.fi - a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
  if (v > 0) return 1;
  else if (v < 0) return -1;
  return 0;
}

ll dist(pll a, pll b) {
  return pow(a.fi-b.fi, 2)+pow(a.se-b.se, 2);
}

bool comp(pll a, pll b) {
  int v = ccw(pivot, a, b);
  if (v == 0) return dist(pivot, a) < dist(pivot, b);
  return v > 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  ll x, y;
  char c;
  int idx;
  for (int i = 0; i < n; i++) {
    cin>>x>>y>>c;
    if (c == 'Y') {
      pll t = {y, x};
      a.push_back(t);
      if (t < pivot) {
        idx = a.size()-1;
        pivot = t;
      }
    } 
  }
  swap(a[idx], a[0]);
  sort(a.begin()+1, a.end(), comp);
  vector<pll> hull;
  hull.push_back(a[0]);
  hull.push_back(a[1]);
  for (int i = 2; i<a.size(); i++) {
    while (hull.size() >= 2) {
      pll se = hull.back(); hull.pop_back(); 
      pll fi = hull.back();
      if (ccw(fi, se, a[i]) > 0) {
        hull.push_back(se);
        break;
      }
    }
    hull.push_back(a[i]);
  }
  cout<<hull.size()<<"\n";
  for (auto [x, y] : hull) cout<<y<<" "<<x<<"\n";
}
