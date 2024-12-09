#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, x;
  cin>>n;
  for (int i = 0; i < n; i++) {
    cin>>x;
    pq.push(x);
  }

  ll ans = 0;
  while (pq.size() >= 2) {
    ll fi = pq.top(); pq.pop();
    ll se = pq.top(); pq.pop();
    ans += fi+se;
    pq.push(fi+se);
  }
  cout<<ans<<"\n";
}
