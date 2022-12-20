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

ll min(ll a, ll b) {
  return a<b?a:b;
}

ll max(ll a, ll b) {
  return a>b?a:b;
}

void solve() {
  ll n, m, ans = 0, x, y;
  scanf("%lld %lld", &x, &y);
  n = min(x, y);
  m = max(x, y);

  if (n == 1 && m <= 2) printf("%lld\n", m-1);
  else if (n == 1 && m > 2) printf("-1\n");
  else {
    ans += 2*(n-1);
    if ((m-n)%2 == 0) ans += 4*((m-n)/2);
    else if ((m-n)%2 == 1) ans += 4*((m-n-1)/2)+1;
    printf("%lld\n", ans);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}