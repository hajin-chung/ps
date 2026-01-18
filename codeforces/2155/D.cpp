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

bool ask(int x, int y) {
  cout<<x<<" "<<y<<"\n"; 
  cout.flush();
  int ret; cin>>ret;
  return ret;
}

void f() {
  int n; cin>>n;
  for (int i = 1; i < n; i++)
    for (int j = 1; j <= n-i; j++)
      if (ask(i, j+i))
        return;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
