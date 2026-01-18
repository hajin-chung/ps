#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

void f() {
  int n; cin>>n;
  deque<int> dq;
  for (int i = 1; i <= n; i++) {
    int x; cin>>x;
    dq.push_back(x);
  }
  vector<int> a;
  string ans;
  for (int i = 1; i <= n/2; i++) {
    int l = dq.front(); dq.pop_front();
    int r = dq.back(); dq.pop_back();
    if (l > r == i%2) ans.append("LR");
    else ans.append("RL");
  }
  if (n%2) ans.push_back('L');
  cout<<ans<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
