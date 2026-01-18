#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long int ll;

int T, N, D;
ll a[100][20][20], cycle[105][20][20];

void matmul(ll a[20][20], ll b[20][20], ll res[20][20]) {
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) res[i][j] = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      for (int k = 0; k < N; k++) {
        res[i][k] += a[i][j] * b[j][k];
        res[i][k] %= MOD;
      }
}

void matpow(ll m[20][20], ll n, ll res[20][20]) {
  if (n == 1) {
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        res[i][j] = m[i][j];
  } else if (n == 0) {
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        res[i][j] = (i == j);
  } else if (n % 2 == 0) {
    ll tmp[20][20];
    matpow(m, n/2, tmp);
    matmul(tmp, tmp, res);
  } else {
    ll tmp[20][20], tmp2[20][20];
    matpow(m, (n-1)/2, tmp);
    matmul(tmp, tmp, tmp2);
    matmul(m, tmp2, res);
  }
}

int main() {
  int i, j, k, m;
  int x, y;
  ll z;

  scanf("%d %d %d", &T, &N, &D);
  for (i = 0; i < T; i++) {
    scanf("%d", &m);
    for (j = 0; j < m; j++) {
      scanf("%d %d %lld", &x, &y, &z);
      a[i][x-1][y-1] = z;
    }
  }

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      for (k = 0; k < T; k++)
        cycle[k][i][j] = (i == j);

  for (i = 0; i < T; i++) matmul(cycle[i], a[i], cycle[i+1]); 

  ll tmp[20][20], res[20][20];
  matpow(cycle[T], D/T, tmp);
  matmul(tmp, cycle[D%T], res);
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++)
      printf("%lld ", res[i][j]);
    printf("\n");
  }
}
