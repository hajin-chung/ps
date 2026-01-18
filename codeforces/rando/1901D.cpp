#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

typedef int64_t ll;
const int N = 3e5;
ll a[N+1];

void f() {
  int n; cin>>n;
  for (int i = 1; i <= n; i++) cin>>a[i];
  multiset<ll> st;
  for (int i = 1; i <= n; i++) st.insert(a[i]+i-1);
  ll ans = *st.rbegin();
  for (int i = 2; i <= n; i++) {
    st.erase(st.find(a[i-1]));
    st.erase(st.find(a[i]+i-1));
    st.insert(a[i-1]+n-(i-1));
    st.insert(a[i]);
    ans = min(ans, *st.rbegin());
  }
  cout<<ans<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  f();
}
