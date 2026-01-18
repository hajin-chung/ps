#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 2e5;
const int INF = 1e9;
typedef long long int ll;

int f() {
  int n; cin>>n;
  vector<ll> o, e;
  for (int i = 0; i < n; i++) {
    ll x; cin>>x;
    if (x%2 == 1) o.push_back(x);
    else e.push_back(x);
  }
  sort(all(o));
  sort(all(e));
  if (e.size() == 0) {
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) cout<<*o.rbegin()<<" ";
      else cout<<"0 ";
    }
    cout<<"\n";
    return 0;
  }
  if (o.size() == 0) {
    for (int i = 0; i < n; i++) cout<<"0 ";
    cout<<"\n";
    return 0;
  }

  reverse(all(e));
  int m = e.size();
  vector<ll> psum(m, 0);
  psum[0] = e[0];
  for (int i = 1; i < m; i++) psum[i] = psum[i-1] + e[i];
  
  ll l1, l2;
  l1 = *o.rbegin();
  cout<<l1<<" ";
  for (int i = 0; i < m; i++) {
    l2 = l1;
    l1 = *o.rbegin() + psum[i];
    cout<<l1<<" ";
  }
  for (int i = 0; i < (o.size()-1) / 2; i++) cout<<l2<<" "<<l1<<" ";
  if (o.size()%2 == 0) cout<<"0";
  cout<<"\n";
  return 0;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t; cin>>t;
  while(t--) f();
}
