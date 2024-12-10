#include <bits/stdc++.h>
using namespace std;

struct P {
  int s, e, m;
};
int sum[2005];

bool comp(P &a, P &b) {
  /*if (a.m == b.m) {*/
  /*  if (a.e == b.e)*/
  /*    return a.s > b.s;*/
  /*  return a.e < b.e;*/
  /*}*/
  /*return a.m > b.m;*/
  if (a.e == b.e) {
    if (a.m == b.m)
      return a.s > b.s;
    return a.m < b.m;
  }
  return a.e < b.e;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, c, m;
  cin>>n>>c>>m;
  vector<P> packs(m);
  for (auto &[s, e, m] : packs) cin>>s>>e>>m;
  sort(packs.begin(), packs.end(), comp);
  int ans = 0;
  for (auto pack : packs) {
    int res, mx = 0;
    for (int j = pack.s; j < pack.e; j++)
      mx = max(mx, sum[j]);
    res = min(c-mx, pack.m);
    for (int j = pack.s; j < pack.e; j++)
      sum[j] += res;
    ans += res;
  }
  cout<<ans<<"\n";
}
