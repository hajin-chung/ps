#include <bits/stdc++.h>
#define N 100000
using namespace std;

int n;
int idx[N+1], a[N+1], b[N+1];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  for (int i = 0; i < n; i++) {
    cin>>a[i];
    idx[a[i]] = i;
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    cin>>b[i];
    b[i] = idx[b[i]];
    if (ans.empty() || ans.back() < b[i]) ans.push_back(b[i]);
    else {
      auto it = lower_bound(ans.begin(), ans.end(), b[i]);
      *it = b[i];
    }
  }
  cout<<ans.size()<<"\n";
}
