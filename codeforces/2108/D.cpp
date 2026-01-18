#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

int ask(int idx) {
  cout<<"? "<<idx<<"\n";
  cout.flush();
  int x; cin>>x;
  return x;
}

void f() {
  int n, k; cin>>n>>k;
  vector<int> ap(k), bp(k);
  for (int i = 0; i < k; i++) ap[i] = ask(i+1);
  for (int i = 0; i < k; i++) bp[i] = ask(n-i);

  // first check a pattern longest
  // then check b pattern longest
  int lb, ub;

  int l = k, r = n-k;
  while (l < r) {
    int m = l + (r-l+1)/2;
    int ret = ask(m);
    if (ap[(m-1)%k] == ret) l = m;
    else r = m-1;
  }
  ub = l;

  l = k+1, r = n-k+1;
  while (l < r) {
    int m = l + (r-l)/2;
    int ret = ask(m);
    if (bp[(n-m)%k] == ret) r = m;
    else l = m+1;
  }
  lb = l;
  if (ub + 1 != lb) cout<<"! -1\n";
  else cout<<"! "<<ub<<" "<<n-ub<<"\n";
  cout.flush();
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
