#include <bits/stdc++.h>
#define N 100000
#define MOD 1000000007
using namespace std;

int bit[12][N+5];
int n;

void update(int u, int idx, int v) {
  while (idx <= N) {
    bit[u][idx] += v;
    bit[u][idx] %= MOD;
    idx += idx&-idx;
  }
}

int query(int u, int idx) {
  int ret = 0;
  while (idx > 0) {
    ret += bit[u][idx];
    ret %= MOD;
    idx -= idx&-idx;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    update(1, x, 1);
    for (int j = 2; j <= 11; j++)
      update(j, x, query(j-1, x-1));
  }
  cout << query(11, N) << "\n";
}
