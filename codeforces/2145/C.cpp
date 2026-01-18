#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

const int N = 2e5;

void f() {
  int n; cin>>n;
  string s; cin>>s;

  vector<vector<int>> b(2*n+1);
  int acnt, bcnt;

  acnt = bcnt = 0;
  for (int i = n; i >= 1; i--) {
    if (s[i-1] == 'a') acnt++;
    else bcnt++;
    b[acnt-bcnt+n].push_back(i);
  }

  for (auto &v : b) reverse(all(v));
  b[n].push_back(n+1);
  int ans = n;
  acnt = bcnt = 0;
  for (int i = 0; i <= n; i++) {
    if (i) {
      if (s[i-1] == 'a') acnt++;
      else bcnt++;
    }

    auto &v = b[bcnt-acnt+n];
    auto it = lower_bound(all(v), i+1);
    if (it != v.end()) ans = min(ans, *it-i-1);
  }

  if (ans == n) cout<<"-1\n";
  else cout<<ans<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
