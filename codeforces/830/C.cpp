#include <stdio.h>
#include <vector>
using namespace std;

typedef long long int ll;

vector<ll> sm, xr;

ll f(int l, int r) {
  return sm[r]-sm[l-1]-(xr[r]^xr[l-1]);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, q, i;
    ll x;
    int l, r;
    int s, e;

    scanf("%d %d", &n, &q);
    sm.resize(n+1, 0);
    xr.resize(n+1, 0);
    for(i=1; i<=n; i++) {
      scanf("%lld", &x);
      sm[i] = sm[i-1] + x;
      xr[i] = xr[i-1] ^ x;
    }

    for(i=1 ; i<=q; i++) {
      scanf("%d %d", &l, &r);
      ll mx = f(l, r);
      int lo, hi, mid;

      lo = l, hi = r;
      while(lo < hi) {
        mid = (lo+hi) >> 1;
        ll flr = f(l, mid);
        if (flr < mx) {
          lo = mid + 1; 
        } else {
          hi = mid;
        }
      }
      e = lo;
    
      lo = l, hi = r;
      while (lo < hi) {
        mid = (lo + hi) >> 1;
        ll flr = f(mid, r);
        if (flr <= mx) {
          hi = mid;
        } else {
          lo = mid+1;
        }
      }
      s = lo;
      printf("%d %d\n", s, e);
      // printf("\n");
    }
  }
}