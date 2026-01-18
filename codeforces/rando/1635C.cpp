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
  int n; cin>>n;
  vector<ll> a(n);
  for (auto &x: a) cin>>x;
  if (a[n-1] < a[n-2]) {
    cout<<"-1\n";
    return;
  }
  vector<tuple<int, int, int>> ans;
  for (int i = n-2; i >= 1; i--) {
    if (a[i] >= a[i-1]) continue;
    if (a[n-1] < 0) {
      cout<<"-1\n";
      return;
    } else {
      a[i-1] = a[i] - a[n-1];
      ans.push_back({i, i+1, n});
    }
  }
  cout<<sz(ans)<<"\n";
  for (auto [x, y, z] : ans) cout<<x<<" "<<y<<" "<<z<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) solve();
}
