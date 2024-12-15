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
  int dx = a.fi - b.fi;
  int dy = a.se - b.se;
  return dx*dx+dy*dy;
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
      pll t = {x, y};
      a.push_back(t);
      if (t < pivot) {
        idx = a.size()-1;
        pivot = t;
      }
    } 
  }
  swap(a[idx], a[0]);
  sort(a.begin()+1, a.end(), comp);
  int n = a.size(), k = n-2;
  while (ccw(a[n-1], a[n-2], a[k-1]) == 0) { k--; }
  reverse(a.begin()+k, a.end());
  cout<<n<<"\n";
  for (auto [x, y] : a) cout<<x<<" "<<y<<"\n";
}
