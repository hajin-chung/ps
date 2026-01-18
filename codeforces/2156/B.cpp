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

void f() {
  int n, q; cin>>n>>q;
  string s; cin>>s;
  bool hasb = 0;
  for (auto c : s)
    if (c == 'B')
      hasb = 1;

  while (q--) {
    int x; cin>>x;
    if (!hasb) {
      cout<<x<<"\n";
      continue;
    }
    int i = 0;
    for (; x; i++) {
      int j = i%n;
      if (s[j] == 'A') x--;
      else x /= 2;
    }
    cout<<i<<"\n";
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
