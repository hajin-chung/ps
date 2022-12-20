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
  ll n, a, b;
  ll i;
  scanf("%lld %lld %lld", &n, &a, &b);
  vector<ll> k(n+1, 0), sum(n+1, 0);
  ll mn = 2e13 + 4;
  for(i=1;i<=n;i++) 
    scanf("%lld",&k[i]), sum[i]=sum[i-1]+k[i];
  // for(i=1;i<=n;i++) printf("%lld ", sum[i]);
  // printf("\n");
  for(i=0;i<=n;i++) {
    ll cost = a*k[i]+ b*k[i] + b*((sum[n]-sum[i])-(n-i)*k[i]);
    // printf("%lld ", cost);
    if (cost < mn) mn = cost;
  }
  printf("%lld\n", mn);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}