#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

void f() {
  int n; cin>>n;
  int mx = 0, s = 0;
  vector<int> c(n+1);
  for (int i = 1; i <= n; i++) {
    cout<<"? "<<i<<" "<<n<<" ";
    for (int j = 1; j <= n; j++) cout<<j<<" ";
    cout<<"\n";
    cout.flush();
    cin>>c[i];
    if (c[i] > mx) {
      s = i;
      mx = c[i];
    }
  }

  set<int> st, at;
  for (int i =  1; i <= n; i++) st.insert(i);
  vector<pair<int, int>> av;
  av.push_back({c[s], s});
  st.erase(s);
  at.insert(s);
  while (!st.empty()) {
    int v = *st.begin();
    st.erase(v);
    int k = at.size() + st.size();
    cout<<"? "<<s<<" "<<k<<" ";
    for (auto x : at) cout<<x<<" ";
    for (auto x : st) cout<<x<<" ";
    cout<<"\n";
    cout.flush();
    int cnt; cin>>cnt;
    if (cnt == mx) continue;
    at.insert(v);
    av.push_back({c[v], v});
  }
  sort(all(av));
  reverse(all(av));
  cout<<"! "<<mx<<" ";
  for (int i = 0; i < mx; i++) cout<<av[i].se<<" ";
  cout<<"\n";
  cout.flush();
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
