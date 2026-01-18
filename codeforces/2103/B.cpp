#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

void f() {
  int n; cin>>n; 
  string s; cin>>s;
  string b;
  b.push_back(s[0]);
  for (int i = 1; i < n; i++)
    if (s[i-1] != s[i])
      b.push_back(s[i]);
  int len = b.size();
  if (b[0] == '0') len--;
  int off = 0;
  if (len == 0) off = 0;
  else if (len <= 3) off = 1;
  else off = len-2;
  cout<<n+off<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
