#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <deque>
#include <stack>
#define MOD 1000000007
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void solve() {
  int n, x, i;
  int idx[100005];
  scanf("%d", &n);
  for(i=0;i<n;i++) scanf("%d", &x), idx[x]=i;
  int l, h, t, tl, th;
  ll cnt = 1;
  h = l = idx[0];
  for(i=1;i<n;i++) {
    if (idx[i] < l) {
      l = idx[i];
    } else if (idx[i] > h) {
      h = idx[i];
    } else {
      cnt = cnt * (h-l+1-i) %MOD;
    }
  }
  printf("%lld\n", cnt);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}