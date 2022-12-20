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

void solve() {
  int n, lo, hi, i;
  ll sum = 0, ans = 0;
  scanf("%d", &n);
  vector<ll> a(n);
  vector<ll> psum(n, 0);
  for(i=0 ; i<n ; i++) {
    scanf("%lld", &a[i]);
    if (i == 0) psum[i] = a[i];
    else psum[i] = psum[i-1] + a[i];
  }
  lo = hi = 0;
  for(hi=0 ; hi<n ; hi++) {
    if (sum > 0 && sum + a[hi] <= 0) {

    } else {
      sum += a[hi];
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}