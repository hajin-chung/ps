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

typedef uint64_t ll;

void f() {
  int n; cin>>n;
  vector<ll> a(2*n);
  for (int i = 0; i < n; i++) cin>>a[i];
  for (int i = n; i < 2*n; i++) a[i] = a[i-n];

  vector<pair<ll, int>> st;
  for (int i = n-1; i >= 0; i--)
    if (st.empty() || a[i] < st.rbegin()->fi)
      st.push_back({a[i], i});
  reverse(all(st));

  ll ans = n;
  int li = -1;
  for (auto p : st) {
    auto [v, i] = p;
    ans += v*(i-li);
    li = i;
  }

  ll psum = ans;
  for (int i = n; i < 2*n; i++) {
    ll sum = psum;
    if (a[i] == 0) {
      st.clear();
      st.push_back({a[i], i});
      sum = n;
    } else {
      sum -= st[0].fi;
      while (!st.empty() && st.rbegin()->fi > a[i]) {
        auto [v, r] = *st.rbegin();
        st.pop_back();
        int l = st.empty() ? -1 : st.rbegin()->se;
        sum -= v*(r-l);
      }
      int l = st.empty() ? -1 : st.rbegin()->se;
      sum += a[i]*(i-l);
      st.push_back({a[i], i});
    }
    psum = sum;
    ans = max(ans, sum);
  }
  cout<<ans<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
