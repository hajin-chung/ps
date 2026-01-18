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

ll gcd(ll a, ll b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void solve() {
  ll a, b, c, d;
  scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
  if (a == c && c == 0) printf("0\n");
  else if (c == 0 || a == 0) printf("1\n");
  else if (a*d == b*c) printf("0\n");
  else if ((a*d)%(b*c) == 0 || (b*c)%(a*d) == 0) printf("1\n");
  else printf("2\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}