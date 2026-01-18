#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

typedef int64_t ll;

void f() {
  int n; ll c; cin>>n>>c;
  vector<ll> a(n); for (auto &x: a) cin>>x;
  sort(all(a));
  reverse(all(a));
  int z = 0;
  for (int i = 0; i < n; i++) {
    int cnt = -1;
    while((a[i]<<(cnt+1)) <= c) cnt++;
    if (cnt != -1 && cnt >= z) z++; 
  }
  cout<<n-z<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
