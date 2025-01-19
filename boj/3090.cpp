#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, t; cin>>n>>t;
  vector<int> a(n);
  for (auto &i : a) cin>>i;
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) r = max(r, abs(a[i]-a[i-1]));
  vector<int> ta, ans;
  while (l < r) {
    int m = (l+r)>>1;
    int cnt = 0;
    ta = a;
    for (int i = 1; i < n; i++) 
      if (ta[i]-ta[i-1] > m) {
        cnt += ta[i]-ta[i-1]-m;
        ta[i] = ta[i-1] + m;
      }
    for (int i = n-2; i >= 0; i--) 
      if (ta[i]-ta[i+1] > m) {
        cnt += ta[i]-ta[i+1]-m;
        ta[i] = ta[i+1] + m;
      }
    if (cnt > t) l = m+1;
    else {
      r = m;
      ans = ta;
    }
  }
  for (auto i : ans) cout<<i<<" ";
  cout<<"\n";
}
