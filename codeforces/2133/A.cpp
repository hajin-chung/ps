#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

void f() {
  int n; cin>>n;
  vector<int> cnt(105);
  bool flag = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin>>x;
    cnt[x]++;
    if (cnt[x] >= 2) flag = 1;
  }
  if (flag) cout<<"YES\n";
  else cout<<"NO\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
