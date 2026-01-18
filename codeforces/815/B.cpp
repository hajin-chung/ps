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
  int n;
  scanf("%d", &n);
  vector<ll> a(n);
  for(int i=0 ; i<n ; i++) scanf("%lld", &a[i]);
  sort(a.begin(), a.end());
  printf("%lld\n", a[n-1]+a[n-2]-a[0]-a[1]);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}