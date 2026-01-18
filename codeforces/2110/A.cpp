#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

void f() {
  int n; cin>>n;
  vector<int> a(n); for (auto &x : a) cin>>x;
  sort(all(a));
  int fecnt = 0, focnt = 0, becnt = 0, bocnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i]%2 == 0) {
      fecnt = i;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i]%2 == 1) {
      focnt = i;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[n-i-1]%2 == 0) {
      becnt = i;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[n-i-1]%2 == 1) {
      bocnt = i;
      break;
    }
  }
  cout<<min(fecnt+becnt, focnt+bocnt)<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
