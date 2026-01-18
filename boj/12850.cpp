#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long int ll;
ll o[8][8] = {
  {0, 1, 1, 0, 0, 0, 0, 0},
  {1, 0, 1, 1, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 0, 0},
  {0, 1, 1, 0, 1, 1, 0, 0},
  {0, 0, 1, 1, 0, 1, 1, 0},
  {0, 0, 0, 1, 1, 0, 0, 1},
  {0, 0, 0, 0, 1, 0, 0, 1},
  {0, 0, 0, 0, 0, 1, 1, 0}
};

void matmul(ll a[8][8], ll b[8][8], ll c[8][8]) {
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
      for (int k = 0; k < 8; k++)
        c[i][k] = (c[i][k] + (a[i][j] * b[j][k]) % MOD) % MOD;
}

int main() {
  ll res[8][8];
  int i, j, n;
  for (i = 0; i < 8; i++)
    for (j = 0; j < 8; j++)
      res[i][j] = i == j ? 1 : 0;
  scanf("%d", &n);
  while (n) {
    if (n & 1) {
      ll tmp[8][8];
      memset(tmp, 0, sizeof(tmp));
      matmul(res, o, tmp);
      memcpy(res, tmp, sizeof(res));
    }
    ll tmp[8][8];
    memset(tmp, 0, sizeof(tmp));
    matmul(o, o, tmp);
    memcpy(o, tmp, sizeof(o));
    n >>= 1;
  }
  printf("%lld\n", res[0][0]);
}
