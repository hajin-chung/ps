#include <bits/stdc++.h>
#define MOD 40000
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

vector<bool> chk;
vector<pll> fire;
int n;

ll f(int lev, ll t) {
  if (lev == n) return t;
  ll ret = -1;
  for (int i = 0; i < n; i++)
    if (!chk[i]) {
      chk[i] = 1;
      int tt = t + fire[i].fi*t + fire[i].se;
      ll ff = f(lev+1, tt);
      if (ff > 0) {
        if (ret == -1) ret = ff;
        else ret = min(ret, ff);
      }
      chk[i] = 0;
    }
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  chk.resize(n, 0); fire.resize(n);
  for (auto &[a, b] : fire)
    cin>>a>>b;
  cout<<f(0, 0)<<"\n";
}
