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
  int n; cin>>n;
  vector<int> a(n); for (auto &x: a) cin>>x;
  int cnt = 0;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(mx, a[i]);
    if (i % 2) a[i] = mx;
  }
  if (a[0] >= a[1]) cnt++;
  for (int i = 1; i+1 < n; i+=2)
    if (a[i+1] >= a[i]) {
      cnt += a[i+1]-a[i]+1;
    }
  cout<<cnt<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
