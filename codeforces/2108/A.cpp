#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

typedef long long ll;

void f() {
  int n; cin>>n;
  ll sum = 0;
  for (int i = 1; i <= n; i++) 
    sum += abs(n-i+1-i);
  cout<<sum/2+1<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
