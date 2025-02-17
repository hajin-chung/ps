#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int a[20], b[20], n;

void flip(int idx, int mask) {
  for (int i = 0; i < n; i++)
    if (mask & (1<<i)) {
      b[idx] ^= (1<<i);
      if (idx != 0) b[idx-1] ^= (1<<i);
      if (idx != n-1) b[idx+1] ^= (1<<i);
      if (i != 0) b[idx] ^= (1<<(i-1));
      if (i != n-1) b[idx] ^= (1<<(i+1));
    }
}

int solve(int mask) {
  int cnt = 0;
  for (int i = 0; i < n; i++) b[i] = a[i];
  for (int i = 0; i < n; i++) {
    cnt += __builtin_popcount(mask);
    flip(i, mask);
    mask = 0;
    for (int j = 0; j < n; j++)
      if (b[i] & (1<<j))
        mask += (1<<j);
  }
  if (b[n-1] != 0) return INF;
  return cnt;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      int x; cin>>x;
      if (x) a[i] += (1<<j);
    }
  int ans = INF;
  for (int i = 0; i < (1<<n); i++) ans = min(ans, solve(i));
  if (ans == INF) cout<<"-1\n";
  else cout<<ans<<"\n";
}
