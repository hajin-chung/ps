#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

typedef uint64_t ll;
const int N = 1e5;
const ll MOD = 998244353;
ll p[N], q[N], pt[N+1];

void f() {
  int n; cin>>n;
  for (int i = 0; i < n; i++) cin>>p[i];
  for (int i = 0; i < n; i++) cin>>q[i];
  int mxp = 0, mxq = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] > p[mxp]) mxp = i;
    if (q[i] > q[mxq]) mxq = i;
    ll pq = (pt[p[mxp]]+pt[q[i-mxp]])%MOD;
    ll qp = (pt[q[mxq]]+pt[p[i-mxq]])%MOD;
    if (p[mxp] > q[mxq]) cout<<pq;
    else if (q[mxq]>p[mxp]) cout<<qp;
    else {
      if (q[i-mxp] > p[i-mxq]) cout<<pq;
      else cout<<qp;
    }
    cout<<" ";
  }
  cout<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  pt[0] = 1;
  for (int i = 1; i <= N; i++)
    pt[i] = pt[i-1]*2LL%MOD;
  int t; cin>>t;
  while(t--) f();
}
