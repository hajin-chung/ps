#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
const int N = 300000;
int n, a[N+1], cnt[N+1];
set<int> idx[N+1];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  int k = 1;
  for (int i = 1; i <= n; i++) {
    cin>>a[i];
    cnt[a[i]]++;
    idx[a[i]].insert(i);
  }
  set<pii> cset;
  set<pii> iset;
  for (int i = 1; i <= n; i++)
    if (cnt[i]) {
      cset.insert({cnt[i], i});
      iset.insert({*idx[i].begin(), i});
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
      auto it = iset.begin();
      if (it->se == last) it++;
      k = it->se;
    }
    cout<<*idx[k].begin()<<" ";
    cset.erase({cnt[k], k});
    cnt[k]--;
    cset.insert({cnt[k], k});
    iset.erase({*idx[k].begin(), k});
    idx[k].erase(idx[k].begin());
    if (idx[k].size()) iset.insert({*idx[k].begin(), k});
    last = k;
  }
  cout<<"\n";
  return 0;
}
