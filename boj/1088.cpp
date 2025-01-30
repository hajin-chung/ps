#include <bits/stdc++.h>
using namespace std;

const double INF = 1e9;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin>>n;
  vector<double> a(n);
  for (auto &x : a) cin>>x;
  cin>>m;
  sort(a.begin(), a.end());
  double ans = INF;
  for (int i = 1; i <= m; i++) {
    int cnt = m-(i-1);
    double mn = a[0]/i, mx = a[0]/i, div = a[0]/i;
    for (int j = 1; j < n; j++) {
      int k1 = min((int)floor(a[j]/div), cnt+1);
      int k2 = min((int)floor(a[j]/div)+1, cnt+1);
      if (abs(div-a[j]/k1) < abs(div-a[j]/k2)) {
        cnt -= (k1-1);
        mn = min(mn, a[j]/k1);
        mx = max(mx, a[j]/k1);
      } else {
        cnt -= (k2-1);
        mn = min(mn, a[j]/k2);
        mx = max(mx, a[j]/k2);
      }
    }
    if (ans < mx-mn) break;
    ans = min(ans, mx-mn);
  }
  cout<<fixed<<setprecision(10);
  cout<<ans<<"\n";
}
