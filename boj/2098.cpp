/*
 * dp[curr][mask] = min dist sum of currently at curr and visited mask 
 * -> n*2^n = 16*65536
*/

#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int n;
int w[20][20], dp[20][(1<<16)+5];

int rec(int curr, int mask) {
  if (mask == (1<<n)-1) {
    if (w[curr][0] == 0) return INF;
    return w[curr][0];
  }
  if (dp[curr][mask] != 0) return dp[curr][mask];
  int ret = INF;
  for (int next = 0; next < n; next++)
    if ((mask & (1<<next)) == 0 && w[curr][next] != 0)
      ret = min(ret, rec(next, mask | (1<<next)) + w[curr][next]);
  return dp[curr][mask] = ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> w[i][j];
  cout << rec(0, 1) << "\n";
}
