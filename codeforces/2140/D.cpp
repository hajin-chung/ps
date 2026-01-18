#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

typedef int64_t ll;

void f() {
  int n; cin>>n;
  vector<pair<ll, ll>> a(n);
  vector<pair<ll, int>> lv, rv;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    ll l, r; cin>>l>>r;
    sum += (r-l);
    lv.push_back({-l, i});
    rv.push_back({r, i});
  }
  sort(all(lv)); reverse(all(lv));
  sort(all(rv)); reverse(all(rv));
  set<int> ridx;
  ll rsum = 0;
  for (int i = 0; i < n/2; i++) {
    rsum += rv[i].fi; 
    ridx.insert(rv[i].se);
  }
  int cnt = n/2;
  for (int i = 0; cnt && i < n; i++)
    if (ridx.count(lv[i].se) == 0) {
      rsum += lv[i].fi;
      cnt--;
    }
  set<int> lidx;
  ll lsum = 0;
  for (int i = 0; i < n/2; i++) {
    lsum += lv[i].fi; 
    lidx.insert(lv[i].se);
  }
  cnt = n/2;
  for (int i = 0; cnt && i < n; i++)
    if (lidx.count(rv[i].se) == 0) {
      lsum += rv[i].fi;
      cnt--;
    }
  cout<<sum+max(lsum, rsum)<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
