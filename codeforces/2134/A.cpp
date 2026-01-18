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
  int n, a, b; cin>>n>>a>>b;
  if (a > b && n%2 == a%2 && n%2 == b%2) cout<<"YES\n";
  else if (a <= b && n%2 == b%2) cout<<"YES\n";
  else cout<<"NO\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
