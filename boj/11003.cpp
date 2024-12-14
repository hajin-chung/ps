#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, l; cin>>n>>l;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin>>a[i];
  multiset<int> ms;
  for (int i = 0; i < n; i++) {
    if (i >= l) {
      auto it = ms.find(a[i-l]);
      ms.erase(it);
    }
    ms.insert(a[i]);
    cout<<*ms.begin()<<" ";
  }
  cout<<"\n";
}
