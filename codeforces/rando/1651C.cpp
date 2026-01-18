#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
const ll INF = 1LL<<60;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void solve() {
  int n; cin>>n;
  vector<ll> a(n); for (auto &x: a) cin>>x;
  vector<ll> b(n); for (auto &x: b) cin>>x;
  ll maf = INF, mae = INF, mbf = INF, mbe = INF;
  for (int i = 0; i < n; i++) {
    maf = min(maf, abs(a[0]-b[i]));
    mae = min(mae, abs(a[n-1]-b[i]));
    mbf = min(mbf, abs(a[i]-b[0]));
    mbe = min(mbe, abs(a[i]-b[n-1]));
  } 
  
  ll ff = min(maf+mbf, abs(a[0]-b[0]));
  ll ee = min(mae+mbe, abs(a[n-1]-b[n-1]));
  ll ca = min(maf+mbe, abs(a[0]-b[n-1]));
  ll cb = min(mae+mbf, abs(a[n-1]-b[0]));
  cout<<min(ff+ee, ca+cb)<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) solve();
}
