#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

void f() {
  int a, b, c, d; cin>>a>>b>>c>>d;
  if (min(a, c) < min(b, d)) {
    cout<<"Flower\n";
  } else {
    cout<<"Gellyfish\n";
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
