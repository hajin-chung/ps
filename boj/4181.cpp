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
    if (c == 'Y') a.push_back({x, y});
  }
  int n = a.size(), k = n-1;
  for (int i = 1; i < n; i++) if (a[0] > a[i]) swap(a[0], a[i]);
  pivot = a[0];
  sort(a.begin()+1, a.end(), comp);
  while (k > 1 && ccw(a[0], a[k], a[k-1]) == 0) k--;
  reverse(a.begin()+k, a.end());

  cout<<n<<"\n";
  for (auto [x, y] : a) cout<<x<<" "<<y<<"\n";
}
