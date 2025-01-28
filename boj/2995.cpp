#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;

struct B {
  int s, e;
  bool operator<(B v) { 
    if (e == v.e) return s > v.s;
    return e < v.e;
  }
};
const int N = 200000;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<B> a(n);
  for (auto &[s, e] : a) cin>>s>>e;
  sort(all(a));
  reverse(all(a));
  vector<int> v, idx(n);
  for (int i = 0; i < n; i++) {
    auto [s, e] = a[i];
    auto it = upper_bound(all(v), s);
    if (it == v.end()) {
      v.push_back(s);
      idx[i] = v.size()-1;
    } else {
      *it = s;
      idx[i] = it-v.begin();
    }
  }
  int len = v.size();
  cout<<len<<"\n";
  vector<B> ans;
  for (int i = n-1; i >= 0 && len > 0; i--)
    if (idx[i] == len-1) {
      ans.push_back(a[i]);
      len--;
    }
  reverse(all(ans));
  for (auto [s, e] : ans) cout<<s<<" "<<e<<"\n";
}
