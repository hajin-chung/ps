#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int p[10] = {0, 1, 2, 2, 3, 3, 3, 3, 4, 4};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, k, x; cin>>n>>k>>x;
  ll ans = (n+1-p[x])-3*(k-1);
  if (x == 4 || x == 8 || x == 9) ans++;
  cout<<ans<<"\n";
}
