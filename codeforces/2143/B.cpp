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

void f() {
  int n, k; cin>>n>>k;
  vector<uint64_t> a(n); for (auto &x: a) cin>>x;
  vector<int> b(k); for (auto &x: b) cin>>x;
  sort(all(a));
  reverse(all(a));
  sort(all(b));

  uint64_t sum = 0;
  int ai = 0;
  for (int i = 0; i < k; i++) {
    if (ai + b[i]-1 < n) {
      for (int j = 0; j < b[i]-1; j++)
        sum += a[ai+j];
      ai += b[i];
    }
  }
  for (; ai < n; ai++)
    sum += a[ai];
  cout<<sum<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
