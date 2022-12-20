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
  int n, i, j, ans = 0;
  int a[513];
  scanf("%d", &n);
  for(i=1 ; i<=n ; i++) scanf("%d", &a[i]);
  int mx, mn;
  mx = mn = a[1];
  for(i=1 ; i<=n ; i++) {
    mx |= a[i];
    mn &= a[i];
  }
  printf("%d\n", mx - mn);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}