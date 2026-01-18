#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long double ld;
typedef pair<ld, int> pli;
const ld INF = 1e9;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin>>n;
  vector<pli> a(n);
  for (int i = 0; i < n; i++) {
    ld x; cin>>x;
    a[i] = {x, 1};
  }
  cin>>m;
  ld ans = INF;
  while (m--) {
    sort(a.begin(), a.end());
    auto [x, cnt] = a.back();
    ans = min(ans, a.back().fi-a.begin()->fi);
    a.back() = {x*cnt/(cnt+1), cnt+1};
  }
  sort(a.begin(), a.end());
  ans = min(ans, a.back().fi-a.begin()->fi);
  cout<<fixed<<setprecision(15);
  cout<<ans<<"\n";
}
