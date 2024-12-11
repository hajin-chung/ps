#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<int> a(n);
  for (auto &ai : a) cin>>ai;
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > ans+1) break;
    else ans += a[i];
  }
  cout<<ans+1<<"\n";
}
