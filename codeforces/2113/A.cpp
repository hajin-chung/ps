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
  int k, a, b, x, y; cin>>k>>a>>b>>x>>y;
  if (x > y) {
    swap(x, y);
    swap(a, b);
  }
  if (x == y && a > b) {
    swap(a, b);
  }

  int cnt = 0;
  if (k >= a) {
    cnt += (k-a)/x + 1;
    k -= cnt*x;
  }

  if (k >= b) {
    cnt += (k-b)/y + 1;
  }
  cout<<cnt<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
