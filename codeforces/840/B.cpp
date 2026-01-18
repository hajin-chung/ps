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
typedef pair<ll, ll> pll;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void solve() {
  int n, i;
  ll sum, x, k;
  scanf("%d %lld", &n, &k);
  vector<pll> mon(n); // pi, hi
  for(i=0 ; i<n ; i++) scanf("%lld", &x), mon[i].second = x;
  for(i=0 ; i<n ; i++) scanf("%lld", &x), mon[i].first = x;
  sort(mon.begin(), mon.end());
  sum = k;
  for(i=0 ; i<n && k > 0 ; i++) {
    while (mon[i].second - sum > 0) {
      k -= mon[i].first;
      if (k <= 0) break;
      sum += k;
    }
  }
  int flag = 0;
  for(i=0 ; i<n ; i++) if (mon[i].second > sum) flag = 1;
  if (flag) printf("NO\n");
  else printf("YES\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}