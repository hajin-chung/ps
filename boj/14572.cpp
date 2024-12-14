#include <bits/stdc++.h>
using namespace std;

int cnt[30];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k, d; cin>>n>>k>>d;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
    int m, d; cin>>m>>d;
    int bits = 0;
    while (m--) {
      int x; cin>>x;
      bits += (1<<(x-1));
    }
    a.push_back({d, bits});
  }
  sort(a.begin(), a.end());
  int ans = 0, lo = 0, hi = 0;
  for (; hi < n; hi++) {
    for (int i = 0; i < k; i++)
      if (a[hi].second & (1<<i))
        cnt[i]++;
    while (a[hi].first - a[lo].first > d) {
      for (int i = 0; i < k; i++) 
        if (a[lo].second & (1<<i))
          cnt[i]--;
      lo++;
    }
    int ac = 0, oc = 0;
    for (int i = 0; i < k; i++) 
      if (cnt[i]) {
        oc++;
        ac += (cnt[i] == (hi-lo+1));
      }
    int e = (oc-ac)*(hi-lo+1);
    ans = max(ans, e);
  }
  cout<<ans<<"\n";
}
