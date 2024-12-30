#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k; cin>>n>>m>>k;
  bool did_swap = m < k;
  if (did_swap) swap(m, k);
  vector<vector<int>> a(m);
  for (int i = 0; i < m; i++) a[i].push_back(n-m+i+1);
  vector<int> r;
  for (int i = n-m; i >= 1; i--) r.push_back(i); 
  if (r.size() < k-1) {
    cout<<"-1\n";
    return 0;
  }
  for (int i = 0; i < m; i++) {
    vector<int> t;
    for (int j = 0; j < k-1 && !r.empty(); j++) {
      t.push_back(r.back());
      r.pop_back();
    }
    reverse(t.begin(), t.end());
    for (auto ti : t)
      a[i].push_back(ti);
  }
  if (!r.empty()) cout<<"-1\n";
  else {
    if (did_swap) {
      reverse(a.begin(), a.end());
      for (auto &v : a)
        reverse(v.begin(), v.end());
    }
    for (auto v : a)
      for (auto vi : v)
        cout<<vi<<" ";
    cout<<"\n";
  }
}
