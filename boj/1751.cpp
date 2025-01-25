#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MOD = 1e9+9;
const int N = 300;
bool a[N+5][N+5], b[N+5][N+5];
ll sum1[N+5][N+5], sum2[N+5][N+5];
ll hi = 2, hj = 3;
int n, m; 

ll mmod(int x) { return (x%MOD+MOD)%MOD; }

ll pow(ll x, int n) {
  ll ret = 1;
  while (n > 0) {
    if (n & 1) ret = ret*x%MOD;
    x = x*x%MOD;
    n>>=1;
  }
  return ret%MOD;
}

ll mhash(int i, int j) { return (pow(hi, i-1)*pow(hj, j-1))%MOD; }

bool chk(int i, int j, int k) {
  ll h1 = mmod(sum1[i+k][j+k]-sum1[i-1][j+k]-sum1[i+k][j-1]+sum1[i-1][j-1])%MOD;
  int oi = i, oj = j;
  i = n-i+1-k; j = m-j+1-k;
  ll h2 = mmod(sum2[i+k][j+k]-sum2[i-1][j+k]-sum2[i+k][j-1]+sum2[i-1][j-1])%MOD;
  int dx = i-oi, dy = j-oj;
  if (dx < 0) h2 = h2*pow(hi, -dx)%MOD;
  else h1 = h1*pow(hi, dx)%MOD;
  if (dy < 0) h2 = h2*pow(hj, -dy)%MOD;
  else h1 = h1*pow(hj, dy)%MOD;
  return h1 == h2;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      char c; cin>>c;
      a[i][j] = c == '1';
      b[n-i+1][m-j+1] = c == '1';
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      sum1[i][j] = mmod(((ll)a[i][j]*mhash(i, j))+sum1[i-1][j]+sum1[i][j-1]-sum1[i-1][j-1])%MOD;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      sum2[i][j] = mmod(((ll)b[i][j]*mhash(i, j))+sum2[i-1][j]+sum2[i][j-1]-sum2[i-1][j-1])%MOD;
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int k = 0; k < min(n-i+1, m-j+1); k++)
        if (k > ans && chk(i, j, k))
          ans = k;
  cout<<ans+1<<"\n";
}
