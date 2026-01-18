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

int len(ll x) {
  int cnt = 0;
  while (x) {
    cnt++;
    x /= 10;
  }
  return cnt;
}

void f() {
  ll x; cin>>x;  
  int xl = len(x);
  ll y = 0;
  for (int i = 1; i <= xl+1; i++)
    y = y*10 + 9; 
  y-=x;
  cout<<y<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
