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
  int n, k; cin>>n>>k;
  set<int> a;
  for (int i = 0; i < n; i++) {
    int x; cin>>x;
    a.insert(x);
  }
  set<int> m(a);
  vector<int> ans;
  while (!m.empty()) {
    auto it = m.begin();
    int mn = *it;
    ans.push_back(mn);
    m.erase(it);
    for (int i = mn; i <= k; i += mn) {
      m.erase(i);
      if (a.count(i) == 0) {
        cout<<"-1\n";
        return;
      }
    }
  }
  cout<<ans.size()<<"\n";
  for (auto x: ans) cout<<x<<" ";
  cout<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) solve();
}
