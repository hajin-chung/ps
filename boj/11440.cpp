#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef tuple<ll,ll,ll,ll> t4i;
const ll MOD = 1e9+7;

t4i mult(t4i &a, t4i &b) {
  auto [a11, a21, a12, a22] = a;
  auto [b11, b21, b12, b22] = b;
  return {
    (a11*b11+a12*b21)%MOD,
    (a21*b11+a22*b21)%MOD,
    (a11*b12+a12*b22)%MOD,
    (a21*b12+a22*b22)%MOD,
  };
}

t4i pow(t4i a, ll n) {
  t4i res = {1, 0, 0, 1};
  while (n>0) {
    if (n&1) res = mult(res, a);
    a = mult(a, a);
    n>>=1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n; cin>>n;
  /*if (n == 1) {*/
  /*  cout<<"1\n";*/
  /*  return 0;*/
  /*}*/
  t4i a = {1, 1, 1, 0};
  auto [fn, fm, x, y] = pow(a, n);
  cout<<fn*fm%MOD<<"\n";
}
