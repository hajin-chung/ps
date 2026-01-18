#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
const int INF = 1e9;

int f() {
  int mx = 0, cnt = 0;
  int n; cin>>n;
  string s; cin>>s;
  int zpre = 0, zpost = 0; 
  while (zpre < s.size() && s[zpre] == '0') zpre++;
  while (zpost < s.size() && s[s.size()-zpost-1] == '0') zpost++;
  mx = zpre + zpost;
  for (int i = 0; i < s.size(); i++) {
    char x = s[i];
    if (x == '1') {
      mx = max(mx, cnt);
      cnt = 0;
    } else cnt++;
  }
  return mx;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t; cin>>t;
  while(t--) cout<<f()<<"\n";
}
