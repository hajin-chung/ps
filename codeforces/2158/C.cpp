#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void solve() {
  int n, k; cin>>n>>k;
  vector<ll> a(n); for (auto &x: a) cin>>x;
  vector<ll> b(n); for (auto &x: b) cin>>x;

  vector<ll> l(n), r(n);
  for (int i = 0; i < n; i++)
    l[i] = a[i] + (i && l[i-1]>0 ? l[i-1] : 0);
  reverse(all(a));
  for (int i = 0; i < n; i++)
    r[i] = a[i] + (i && r[i-1]>0 ? r[i-1] : 0);
  reverse(all(a)); reverse(all(r));

  if (k%2 == 0) {
    cout<<*max_element(all(l))<<"\n";
    return;
  }

  ll ans = -(1LL<<60);
  for (int i = 0; i < n; i++)
    ans = max(ans, l[i]+r[i]-a[i]+b[i]);
  cout<<ans<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) solve();
}
