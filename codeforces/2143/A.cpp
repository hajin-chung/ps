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
  int si, ei;
  for (int i = 0; i < n; i++)
    if (a[i] == n)
      si = ei = i;
  for (int i = n-1; i >= 1; i--) {
    if (si-1 >= 0 && a[si-1] == i) si--;
    else if (ei+1 < n && a[ei+1] == i) ei++;
    else {
      cout<<"NO\n";
      return;
    }
  }
  cout<<"YES\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
