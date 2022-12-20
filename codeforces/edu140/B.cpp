#include <stdio.h>
#include <math.h>
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
  int n, i;
  vector<ll> a;
  scanf("%d", &n);
  a.resize(n);
  for(i=0 ; i<n ; i++) scanf("%lld", &a[i]);
  sort(a.begin()+1, a.end());
  for(i=1 ; i<n ; i++) {
    if (a[0] < a[i]) a[0] = (a[0]+a[i])/2 + ((a[0]+a[i])%2);
  }
  printf("%lld\n", a[0]);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}