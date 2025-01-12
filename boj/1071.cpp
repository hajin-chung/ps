#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  multiset<int> ms;
  for (int i = 0; i < n; i++) {
    int x; cin>>x;
    ms.insert(x);
  }
  vector<int> ans;
  while (!ms.empty()) {
    if (*ms.begin() + 1 == *ms.rbegin()) {
      for (auto it = ms.rbegin(); it != ms.rend(); it++)
        ans.push_back(*it);
      ms.clear();
    } else {
      if (ans.empty()) {
        ans.push_back(*ms.begin());
        ms.erase(ms.begin());
      } else if (ans.back() + 1 == *ms.begin()) {
        auto next = ms.upper_bound(ans.back()+1);
        if (next == ms.end()) __builtin_unreachable();
        ans.push_back(*next);
        ms.erase(next);
      } else {
        ans.push_back(*ms.begin());
        ms.erase(ms.begin());
      }
    }
  }
  for (auto i : ans) 
    cout<<i<<" ";
  cout<<"\n";
}
