#include <bits/stdc++.h>
#define MOD 1000003
using namespace std;

typedef long long int ll;
typedef vector<vector<ll>> mat;

int n, s, e, t;
mat a, ans;
mat operator *(mat &a, mat &b) {
  mat res(5*n+1, vector<ll>(5*n+1));
  for (int i = 1; i <= 5*n; i++)
    for (int j = 1; j <= 5*n; j++)
      for (int k = 1; k <= 5*n; k++) {
        res[i][k] += a[i][j] * b[j][k];
        res[i][k] %= MOD;
      }
  return res;
}

void matpow() {
  while (t) {
    if (t%2) ans = ans * a;
    t /= 2;
    a = a * a;
  }
}

int main() {
  scanf("%d%d%d%d", &n, &s, &e, &t);
  a.resize(5*n+1, vector<ll>(5*n+1));
  ans.resize(5*n+1, vector<ll>(5*n+1));
  for (int i = 1; i <= n; i++) {
    char tmp[12];
    scanf("%s", tmp);
    for (int j = 1; j <= n; j++) {
      ll w = tmp[j-1] - '0';
      if (1 <= w && w <= 5)
        a[5*i][5*j - w + 1] = 1;
    }
    for (int j = 1; j <= 4; j++)
      a[5*(i-1) + j][5*(i-1) + j + 1]= 1;
  }
  for (int i = 1; i <= 5*n; i++) ans[i][i] = 1;
  matpow();
  printf("%lld\n", ans[5*s][5*e]);
}
