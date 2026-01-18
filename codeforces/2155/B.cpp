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
  if (n*n-k == 1) {
    cout<<"NO\n";
    return;
  } 

  cout<<"YES\n";
  if (n*n == k) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) cout<<"L";
      cout<<"\n";
    }
    return;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= n; j++) {
      if (k) {
        cout<<"L";
        k--;
      } else {
        cout<<"D";
      }
    }
    cout<<"\n";
  }
  for (int i = 1; i <= n-2; i++) {
    if (k) {
      cout<<"L";
      k--;
    } else {
      cout<<"R";
    }
  }
  cout<<"RL\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
