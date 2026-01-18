#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<int> midx, a;
vector<bool> chk;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k; cin>>n>>k;
  midx.resize(k+1);
  chk.resize(k+1);
  a.resize(k);
  for (int i = 0; i < k; i++) {
    cin>>a[i];
    midx[a[i]] = max(midx[a[i]], i);
  }
  int cnt = 0, ans = 0;
  for (int i = 0; i < k; i++) {
    if (chk[a[i]]) continue;
    if (cnt == n) {
      auto [tmp, q] = pq.top();
      pq.pop();
      chk[q] = false;
      cnt--;
      ans++;
    }
    pq.push({midx[a[i]], a[i]});
    chk[a[i]] = true;
    cnt++;
  }
  cout<<ans<<"\n";
}
