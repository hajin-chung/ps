#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int N = 2e5;

void f() {
  int n; cin>>n;  
  vector<int> u(n+1); for (int i = 1; i <= n; i++) cin>>u[i];
  vector<int> d(n+1); for (int i = 1; i <= n; i++) cin>>d[i];

  vector<int> umx(n+5), dmx(n+5), umn(n+5), dmn(n+5);
  umn[0] = dmn[n+1] = INF;
  for (int i = 1; i <= n; i++) {
    umx[i] = max(umx[i-1], u[i]);
    umn[i] = min(umn[i-1], u[i]);
  }
  for (int i = n; i >= 1; i--) {
    dmx[i] = max(dmx[i+1], d[i]);
    dmn[i] = min(dmn[i+1], d[i]);
  }

  vector<int> lr(2*n+5, INF);
  for (int i = 1; i <= n; i++) {
    int mn = min(umn[i], dmn[i]);
    int mx = max(umx[i], dmx[i]);
    lr[mn] = min(lr[mn], mx);
  }
  ll ans = 0;
  for (int i = 2*n; i >= 1; i--) {
    lr[i] = min(lr[i], lr[i+1]);
    if (lr[i] < INF) ans += (ll)(2*n-lr[i]+1); 
  }
  cout<<ans<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
