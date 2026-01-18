#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void solve() {
  int n; cin>>n;
  vector<ll> a(n); for (auto &x : a) cin>>x;
  set<pair<ll, int>> pq;
  vector<int> l2r(n), r2l(n);
  for (int i = 0; i < n; i++) l2r[i] = (i+1)%n;
  for (int i = 0; i < n; i++) r2l[i] = (i-1+n)%n;
  pq.insert({max(a[0], a[n-1]), n-1});
  for (int i = 1; i < n; i++) pq.insert({max(a[i], a[i-1]), i-1});
  ll ans = 0;
  while (pq.size() > 2) {
    auto it = pq.begin();
    ans += it->fi;
    int l = it->se, r = l2r[it->se];
    int ll = r2l[l], rr = l2r[r], mm = (a[l] > a[r]) ? l : r;
    pq.erase({max(a[l], a[r]), l});
    pq.erase({max(a[r], a[rr]), r});
    pq.erase({max(a[ll], a[l]), ll});
    pq.insert({max(a[ll], a[mm]), ll});
    pq.insert({max(a[mm], a[rr]), mm});
    l2r[ll] = mm; r2l[mm] = ll;
    l2r[mm] = rr; r2l[rr] = mm;
  }
  ans += pq.begin()->fi;
  cout<<ans<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) solve();
}
