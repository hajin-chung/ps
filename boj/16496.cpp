#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<ll> a;

ll tpow(ll n) {
  ll ret = 1;
  while(n--) ret*=10;
  return ret;
}

int log_10(ll n) {
  int cnt = 0;
  while (n) {
    cnt++;
    n/=10;
  }
  return cnt;
}

bool cmp(ll a, ll b) {
  int k = 14;
  int an = log_10(a), bn = log_10(b);
  a *= tpow(k-an); 
  a += (tpow(k-an)-1);
  b *= tpow(k-bn); 
  b += (tpow(k-bn)-1);
  return a > b;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n; a.resize(n);
  bool zflag = true;
  for (int i = 0; i < n; i++) {
    cin>>a[i];
    if (a[i] != 0) zflag = false;
  }
  if (zflag) {
    cout << "0\n";
    return 0;
  }
  sort(a.begin(), a.end(), cmp);
  for (int i = 0; i < n; i++)
    cout<<a[i];
  cout<<"\n";
}
