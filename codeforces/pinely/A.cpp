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
  int a, b, n;
  scanf("%d %d %d", &n, &a, &b);
  if (n == a && a == b) printf("YES\n");
  else if (a + b + 2 <= n) printf("YES\n");
  else printf("NO\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}