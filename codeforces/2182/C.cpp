#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll chk(vector<int> &a, vector<int> &b) {
  int n = a.size();
  ll cnt = 0;
  for (int s = 0; s < n; s++) {
    bool ok = 1;
    for (int i = 0; i < n; i++)
      if (a[i] >= b[(i+s)%n]) {
        ok = 0;
        break;
      }
    if (ok) cnt++;
  }
  return cnt;
}

ll f() {
  int n; cin>>n;
  vector<vector<int>> a(3, vector<int>(n));
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < n; j++) cin>>a[i][j];

  ll ans = (ll)n * chk(a[0], a[1]) * chk(a[1], a[2]);
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) cout<<f()<<"\n";
}
