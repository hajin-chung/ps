#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;

struct B {
  int s, e;
  bool operator<(B b) { return b.s <= s && e <= b.e; }
};
const int N = 200000;

bool comp(B &u, B &v) {
  if (u.e == v.e) return u.s > v.s;
  return u.e < v.e;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<B> a(n);
  for (auto &[s, e] : a) cin>>s>>e;
  sort(all(a));
  for (auto [s, e] : a) cout<<s<<" "<<e<<"\n";
  vector<B> v;
  vector<int> idx(n);
  for (int i = 0; i < n; i++) {
    auto b = a[i];
    auto it = lower_bound(all(v), b);
    if (it == v.end()) {
      v.push_back(b);
      idx[i] = v.size()-1;
    } else {
      *it = b;
      idx[i] = it-v.begin();
    }
  }
  int len = v.size();
  cout<<len<<"\n";
  for (int i = n-1; i >= 0 && len > 0; i--) {
    if (idx[i] == len-1) {
      cout<<a[i].s<<" "<<a[i].e<<"\n";
      len--;
    }
  }
}
