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
typedef pair<ll, int> pli;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void solve() {
  ll n, mn;
  ll x;
  ll i;
  scanf("%lld", &n);
  vector<pli> a(0);
  vector<pli> ans(0);
  for(i=0 ; i<n; i++) scanf("%lld", &x), a.push_back({x, i+1});
  sort(a.begin(), a.end());
  for(i=1;i<n;i++) {
    if (a[i].first % a[i-1].first == 0) {
      continue;
    } else if (a[i].first < a[i-1].first) {
      ans.push_back({a[i-1].first - a[i].first, a[i].second});
      a[i].first = a[i-1].first;
      // printf("%lld ", i);
    } else {
      ans.push_back({a[i-1].first-(a[i].first % a[i-1].first), a[i].second});
      a[i].first += a[i-1].first-(a[i].first%a[i-1].first);
      // printf("%lld ", a[i].first);
    }
  }
  // for(i=0 ; i<n; i++) printf("%lld ", a[i].first);
  printf("%d\n", ans.size());
  int len = ans.size();
  for(i=0; i<len;i++) printf("%d %lld\n", ans[i].second, ans[i].first);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}