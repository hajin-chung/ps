#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<int> a(n+1);
  map<int, int> mp;
  set<pii> st;
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin>>x;
    if (!mp.count(x)) mp[x] = cur++;
    a[i] = mp[x];
    st.insert({a[i], i});
  }
  vector<int> ans(n+1);
  ans[1] = 1;
  st.erase(st.begin());
  for (int i = 2; i <= n; i++) {
    cout<<ans[i-1]<<" ";
    if (a[ans[i-1]] == st.begin()->fi) {
      auto it = st.upper_bound({a[ans[i-1]], INF});
      if (it == st.end()) {
        cout<<"-1\n";
        return 0;
      }
      ans[i] = it->se; st.erase(it);
    } else {
      ans[i] = st.begin()->se;
      st.erase(st.begin());
    }
  }
  for (auto ai : ans) cout<<ai<<" ";
  cout<<"\n";
}
