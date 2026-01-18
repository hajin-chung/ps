#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void f() {
  int n; cin>>n;
  vector<int> a(n); for (auto &x: a) cin>>x;
  sort(all(a));
  for (int i = 1; i+1 < n; i += 2)
    if (a[i] != a[i+1]) {
      cout<<"NO\n";
      return;
    }
  cout<<"YES\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
