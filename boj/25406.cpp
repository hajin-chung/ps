#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
const int N = 300000;
int n, a[N+1], cnt[N+1];
map<int, int> mp;
set<pii> cset, iset;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  int k = 1;
  for (int i = 1; i <= n; i++) {
    int x; cin>>x;
    if (!mp.count(x)) mp[x] = k++;
    a[i] = mp[x];
    cnt[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i])
      cset.insert({cnt[i], i});
    iset.insert({a[i], i});
  }
  if (2*cset.rbegin()->fi > n+1) {
    cout<<"-1\n";
    return 0;
  }
  int last = -1;
  for (int i = n; i >= 1; i--) {
    int k;
    if (2*cset.rbegin()->fi == i+1) k = cset.rbegin()->se;
    else {
      k = iset.begin()->fi;
      if (k == last) k = iset.upper_bound({k+1, -1})->fi;
    }
    auto it = iset.lower_bound({k, -1});
    cout<<it->se<<" ";
    cset.erase({cnt[k], k});
    cnt[k]--;
    cset.insert({cnt[k], k});
    iset.erase(it);
    last = k;
  }
  cout<<"\n";
  return 0;
}
