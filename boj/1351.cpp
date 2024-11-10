#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
unordered_map<ll, ll> mp;
ll n, p, q;

ll rec(int a) {
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
