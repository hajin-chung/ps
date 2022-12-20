#include <stdio.h>
#include <stack>
#include <algorithm>

typedef long long ll;

using namespace std;

ll n, a[100005];

int main() {
  int i;
  stack<ll> s;
  ll mx;

  while(1) {
    mx = 0;
    scanf("%lld", &n);
    if (!n) break;

    for (i=0 ; i<n ; i++) {
      scanf("%lld", &a[i]);
      while(!s.empty() && a[s.top()] > a[i]) {
        mx =  max(mx, (a[s.top()] * (i-s.top()-1)));
        s.pop();
      }
      s.push(i);
    }
    while(!s.empty()) {
      mx =  max(mx, (a[s.top()] * n));
      s.pop();
    }
    printf("%d\n", mx);
  }
}