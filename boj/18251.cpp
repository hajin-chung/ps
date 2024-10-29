#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

typedef long long int ll;
int n, ml;
vector<ll> weights;
vector<int> depth, inorder;

void traverse(int idx, int lev) {
  if (idx * 2 > n) {
    ml = lev;
    inorder.push_back(idx);
    depth.push_back(lev);
    return;
  }
  traverse(idx*2, lev+1);
  inorder.push_back(idx);
  depth.push_back(lev);
  traverse(idx*2+1, lev+1);
}

ll rectsum(int lo, int hi) {
  ll mn = 0, sum = 0, mx = 0;
  for (int i = 0; i < n; i++)
    if (lo <= depth[i] && depth[i] < hi) {
      sum += weights[inorder[i]];
      ll csum = sum - mn;
      mn = min(mn, sum);
      mx = max(mx, csum);
    }
  return mx;
}

int main() {
  ll mx = -INF;
  scanf("%d", &n);
  weights.resize(n+1);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &weights[i]);
    mx = max(mx, weights[i]);
  }
  traverse(1, 0);
  ll ans = 0;
  for (int lo = 0; lo <= ml; lo++)  
    for (int hi = lo+1; hi <= ml+1; hi++)
      ans = max(ans, rectsum(lo, hi));
  if (ans == 0 && mx <= 0) printf("%lld\n", mx);
  else printf("%lld\n", ans);
}
