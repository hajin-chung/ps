#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int N = 100000;
int n, d;
ll v[N], t[N], ans[N];

void f(int l, int r, int s, int e) {
  int m = (l+r)>>1, ns = e;
  int qs = max(m+1, s), qe = min(s+d, e);
  for (int i = qs; i <= qe; i++) {
    ll c = v[m]+(ll)(i-m)*t[i];
    if (ans[m] < c) {
      ns = i;
      ans[m] = c;
    }
  }
  /*cout<<l<<" "<<m<<" "<<r<<" "<<s<<" "<<e<<"\n";*/
  if (l != m) f(l, m-1, s, ns);
  if (r != m) f(m+1, r, ns, e);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>d;
  for (int i = 0; i < n; i++) cin>>t[i];
  for (int i = 0; i < n; i++) cin>>v[i];
  f(0, n, 0, n-1);
  cout<<*max_element(ans, ans+n)<<"\n";
}
