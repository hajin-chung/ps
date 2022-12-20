#include <stdio.h>
#include <map>
#define INF 1000000000000000000
using namespace std;

typedef long long int ll;

int main() {
  int q, i;
  char o;
  ll x;
  map<ll, bool> mp;
  scanf("%d", &q);
  for(i=0; i<q; i++) {
    scanf(" %c %lld", &o, &x);
    if (o == '+') mp[x] = 1;
    else if (o == '-') mp[x] = 0;
    else {
      ll mx = (ll)(INF/x) * x;
      ll l = 1, h = mx, mid;
      while(l < h) {
        mid = (l+h) >> 1;
        if (mp[mid * x] == 0) {
          h = mid;
        } else {
          l = mid+1;
        }
      }
      printf("%lld\n", l*x);
    }
  }
}