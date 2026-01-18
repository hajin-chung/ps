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

int mex(int l, int r) {
  cout<<"? "<<l<<" "<<r<<"\n";
  cout.flush();
  int ret; cin>>ret;
  return ret;
}

void f() {
  int n, q; cin>>n>>q;
  vector<int> mxr(n+1, 0);
  for (int i = 1; i <= q; i++) {
    int l, r; cin>>l>>r;
    mxr[l] = max(mxr[l], r);
  }
  vector<pair<int, int>> p;
  int mx = 0;
  for (int i = 1; i <= n; i++) 
    if (mxr[i] > mx) {
      p.push_back({i, mxr[i]});
      mx = mxr[i];
    }
  int l = 0, r = sz(p);
  int ans = 0;
  while (l < r) {
    int m = (l+r)>>1;
    int ml = p[m].fi, mr = p[m].se;
    int mexl = mex(1, mr);
    int mexr = mex(ml, n);
    ans = max(ans, min(mexl, mexr));
    if (mexl > mexr) r = m;
    else l = m+1;
  }
  cout<<"! "<<ans<<"\n";
  cout.flush();
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
