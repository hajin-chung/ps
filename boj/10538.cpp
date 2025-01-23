#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MOD = 1000000009;
const int N = 2000;
ll hy = 2, hx = 3;
ll ph, s[N+1][N+1];

ll pow(ll a, int x) {
  ll ret = 1;
  while (x>0) {
    if (x&1)
      ret *= a;
    a = a*a;
    a %= MOD; ret %= MOD;
    x>>=1;
  }
  return ret;
}

ll mhash(int y, int x) { return pow(hy, y)%MOD*pow(hx, x)%MOD; }

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int pn, pm, sn, sm; cin>>pn>>pm>>sn>>sm;
  for (int i = 0; i < pn; i++)
    for (int j = 0; j < pm; j++) {
      char c; cin>>c;
      if (c == 'o') {
        ph += mhash(i, j);
        ph %= MOD;
      }
    }
  for (int i = 1; i <= sn; i++)
    for (int j = 1; j <= sm; j++) {
      char c; cin>>c;
      if (c == 'o')
        s[i][j] = mhash(i-1, j-1);
      s[i][j] = s[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
      s[i][j] %= MOD;
    }
  int cnt = 0;
  for (int i = pn; i <= sn; i++)
    for (int j = pm; j <= sm; j++) {
      int dy = i-pn, dx = j-pm;
      ll pph = (ph*pow(hy, dy)%MOD)*pow(hx, dx)%MOD;
      ll ssh = s[i][j]-s[i-pn][j]-s[i][j-pm]+s[i-pn][j-pm];
      if (pph == ssh) cnt++;
    }
  cout<<cnt<<"\n";
}
