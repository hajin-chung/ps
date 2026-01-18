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
  vector<int> a(n+1); 
  for (int i = 1; i <= n; i++) cin>>a[i];
  for (int i = 1; i <= n-2; i++) {
    vector<int> lu(n+1);
    for (int j = n; j >= i+1; j--) {
      for (int k = a[j]; k >= 3; k-=2) {
        if (lu[k-1] && lu[k-2]) {
          a[j] -= 2;
          a[lu[k-1]]++;
          a[lu[k-2]]++;
          lu[a[lu[k-1]]] = lu[k-1];
          lu[a[lu[k-2]]] = k-2;
        }
      }
      lu[a[j]] = j;
    }
    for (int j = i+1; j <= n; j++) lu[a[j]] = j;
    for (int j = a[i]; j >= 3; j -= 2) {
      if (lu[j-1] && lu[j-2]) {
        a[i] -= 2;
        a[lu[j-1]]++;
        a[lu[j-2]]++;
      }
      else break;
    }
  }
  for (int i = 1; i <= n; i++) cout<<a[i]<<" ";
  cout<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
