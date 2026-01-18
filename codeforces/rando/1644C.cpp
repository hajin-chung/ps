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

void solve() {
  int n; ll x; cin>>n>>x;
  vector<ll> a(n+1), psum(n+1);
  for (int i = 1; i <= n; i++) {
    cin>>a[i];
    psum[i] = psum[i-1]+a[i];
  }
  vector<ll> ans(n+1);
  for (int l = 0; l <= n; l++)
    for (int i = l; i <= n; i++) 
      ans[l] = max(ans[l], psum[i]-psum[i-l]+x*l);
  for (int i = 0; i <= n; i++)
    for (int j = i+1; j <= n; j++)
      ans[i] = max(ans[i], ans[j] - (j-i)*x);
  for (int i = 1; i <= n; i++) ans[i] = max(ans[i], ans[i-1]);
  for (auto x : ans) cout<<x<<" ";
  cout<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) solve();
}
