#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;

struct B {
  int s, e;
  bool operator<(B &t) {
    if (e-s == t.e-t.s) return s < t.s;
    return e-s<t.e-t.s;
  }
};
const int N = 200000;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<B> a(n);
  for (auto &[s, e] : a) cin>>s>>e;
  sort(all(a));
  for (auto [s, e] : a) cout<<s<<" "<<e<<"\n";
  vector<int> path(n);

}
