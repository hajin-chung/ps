#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<int> ans;
  ans.push_back(1);
  for (int i = 2; i <= n; i++) {
    ans.push_back(i);
    int u = i-1;
    while (u) {
      int v = u>>1;
      if (ans[v] < ans[u]) swap(ans[v], ans[u]);
      u = v;
    }
  }
  for (auto ai : ans) cout<<ai<<" ";
  cout<<"\n";
}
