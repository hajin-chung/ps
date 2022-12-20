#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <deque>
#include <stack>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

ll max(ll a, ll b) {
  return a > b ? a : b;
}

void solve() {
  ll n, x, y, z, mx = 0;
  scanf("%lld", &n);
  if (n == 2) {
    scanf("%lld %lld", &x, &y);
    printf("%lld\n", (x+y>2*abs(y-x))?x+y:2*abs(y-x));
  } else if (n == 3) {
    scanf("%lld %lld %lld", &x, &y, &z);
    mx = max(mx, x+y+z);
    mx = max(mx, 3*x);
    mx = max(mx, 3*z);
    mx = max(mx, 3*abs(x-z));
    mx = max(mx, 3*abs(x-y));
    mx = max(mx, 3*abs(z-y));
    printf("%lld\n", mx); 
  } else {
    for(int i=0; i<n; i++) {
      scanf("%lld", &x);
      if (x > mx) mx = x;
    }
    printf("%lld\n", mx*n);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}