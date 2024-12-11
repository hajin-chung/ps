#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;

bool comp(pii a, pii b) {
  if (a.se == b.se) return a.fi < b.fi;
  return a.se < b.se;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<pii> a(n), b;
  for (auto &[f, s] : a) cin>>f>>s;
  sort(a.begin(), a.end(), comp);
  int ans = 0;
  while (!a.empty()) {
    int ls = a[0].se;
    ans++;
    for (int i = 1; i < a.size(); i++) {
      if (a[i].fi >= ls) {
        ls = a[i].se;
      } else {
        b.push_back(a[i]);
      }
    }
    a = b;
    b.clear();
    sort(a.begin(), a.end(), comp);
  }
  cout<<ans<<"\n";
}
