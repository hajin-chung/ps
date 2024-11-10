#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> mp;
int n, p, q;

int rec(int a) {
  if (mp.count(a)) return mp[a];
  mp[a] = rec(a/p) + rec(a/q);
  return mp[a];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>p>>q;
  mp[0] = 1;
  cout<<rec(n)<<"\n";
}
