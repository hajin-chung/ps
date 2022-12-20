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
  int n, i;
  ll m, sum = 0;
  scanf("%d %lld", &n, &m);
  vector<ll> a(n);
  for(i=0 ; i<n ; i++) scanf("%lld", &a[i]);
  sort(a.begin(), a.end());
  sum = a[n-1]+1;
  for(i=n-2;  i>=0 ; i--) sum += a[i+1] + 1;
  if (sum > m) printf("NO\n");
  else printf("YES\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}