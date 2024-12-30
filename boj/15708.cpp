#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pli;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, t, p; cin>>n>>t>>p;
  priority_queue<pli, vector<pli>, greater<>> pq;
  for (ll i = 0; i < n; i++) {
    ll x; cin>>x;
    pq.push({x+i*p, i});
  }
  ll mx = 0, cnt = 0;
  while (!pq.empty()) {
    auto [cost, idx] = pq.top(); pq.pop(); 
    if (idx > mx) cost -= mx*p;
    else cost -= idx*p;
    mx = max(idx, mx);
    if (t < cost) break;
    t -= cost;
    cnt++;
  }
  cout<<cnt<<"\n";
}
