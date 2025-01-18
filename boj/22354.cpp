#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  string s; cin>>s;
  vector<int> a(n);
  for (auto &x : a) cin>>x;
  vector<int> v;
  v.push_back(a[0]);
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i-1])
      v[v.size()-1] = max(v.back(), a[i]);
    else v.push_back(a[i]);
  }
  n = v.size();
  v[0] = v[n-1] = 0;
  sort(v.begin(), v.end(), greater<int>());
  ll sum = 0;
  for (int i = 0; i < (n-1)/2; i++) sum += (ll)v[i];
  cout<<sum<<"\n";
}
