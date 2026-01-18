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
const int N = 1e5;
ll a[N+1];

void f() {
  int n; ll k; cin>>n>>k;
  for (int i = 1; i <= n; i++) cin>>a[i];
  if (k == 1) {
    for (int i = 1; i <= n; i++) {
      if (a[i]%2 == 1) cout<<a[i]+1<<" ";
      else cout<<a[i]<<" ";
    }
    cout<<"\n";
    return;
  } else if (k == 2) {
    for (int i = 1; i <= n; i++) {
      if (a[i]%3 == 0) cout<<a[i]<<" ";
      else if (a[i]%3 == 1) cout<<a[i]+2<<" ";
      else cout<<a[i]+4<<"\n";
    }
    return;
  }

  for (int i = 1; i <= n; i++) {
    a[i] = a[i] + (k-1-a[i]%(k-1))*k;
  }
  for (int i = 1; i <= n; i++) cout<<a[i]<<" ";
  cout<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
