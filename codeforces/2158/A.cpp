#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void solve() {
  int n, y, r; cin>>n>>y>>r;
  cout<<min(n, y/2+r)<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) solve();
}
