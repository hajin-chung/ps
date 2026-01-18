#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) {
    int x; cin>>x;
    int ans = 10;
    for (; x; x /= 10)
      ans = min(ans, x%10);
    cout<<ans<<"\n";
  }
}
