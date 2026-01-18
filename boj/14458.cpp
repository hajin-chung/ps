#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 100000;
ll bit[N+1];
int a[2][N+1], idx[N+1], n;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  for (int i = 1; i <= n; i++) cin>>a[0][i];
  for (int i = 1; i <= n; i++) cin>>a[1][i];
  ll ans = 1e15, icnt = 0;
  for (int i = 1; i <= n; i++) idx[a[1][i]] = i;
  for (int i = n; i >= 1; i--) {
    for (int j = idx[a[0][i]]; j; j -= j&-j) icnt += bit[j];
    for (int j = idx[a[0][i]]; j <= n; j += j&-j) bit[j]++;
  }
  for (int it = 0; it < 2; it++) {
    ll cnt = icnt; ans = min(ans, cnt);
    for (int i = 1; i <= n; i++) idx[a[1-it][i]] = i;
    for (int i = 1; i <= n; i++) {
      cnt += -idx[a[it][i]]*2+1+n;
      ans = min(ans, cnt);
    }
  }
  cout<<ans<<"\n";
}
