#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long int ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, t, p; cin>>n>>t>>p;
  priority_queue<ll> pq;
  ll sum = 0, ans = 0;
  for (ll i = 0; i < n; i++) {
    ll k; cin>>k;
    sum += k;
    pq.push(k);
    while (!pq.empty() && sum + i*p > t) {
      sum -= pq.top();
      pq.pop();
    }
    ans = max(ans, (ll)pq.size());
  }
  cout<<ans<<"\n";
}
