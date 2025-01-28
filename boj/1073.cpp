#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int cnt[10], d[10];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  while (n--) {
    int x; cin>>x;
    cnt[x/10]++; cnt[x%10]++;
  }
  d[0] = 1;
  for (int i = 2; i <= 8; i+=2) d[i] = (i-1)*d[i-2];
  ll ans = 1;
  for (int i = 0; i < 10; i++) ans *= d[cnt[i]];
  cout<<ans<<"\n";
}
