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
  if (n%2 == 1) printf("-1\n");
  else printf("0 %d %d\n", n/2, n/2);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}