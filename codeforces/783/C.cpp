#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

typedef long long int ll;

int main() {
  int n, i, j;
  ll ans = -1;
  scanf("%d", &n);
  vector<ll> a(n);
  for(i=0 ; i<n ; i++) scanf("%lld", &a[i]);
  for(i=0 ; i<n ; i++) {
    ll cnt = 0;
    vector<ll> d(n, 0);
    for(j=i-1 ; j>=0 ; j--) {
      ll dc = ((ll)ceil((double)(-d[j+1]+1)/a[j]));
      cnt += dc;
      d[j] = -dc * a[j];
    }
    for(j=i+1 ; j<n ; j++) {
      ll dc = ((ll)ceil((double)(d[j-1]+1)/a[j]));
      cnt += dc;
      d[j] = dc * a[j];
    }
    if (ans == -1) ans = cnt;
    else if (cnt < ans) ans = cnt;
  }
  printf("%lld\n", ans);
}