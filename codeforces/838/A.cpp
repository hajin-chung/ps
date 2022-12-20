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
  int n, x, mn = 100000000, sum = 0;
  scanf("%d", &n);
  while(n--) {
    scanf("%d", &x);
    sum += x;
    int cnt = 1;
    while(x) {
      if (x%2 != (int)(x/2)%2) break;
      x /= 2;
      cnt++;
    }
    if (cnt < mn) mn = cnt;
  }
  if (sum%2==0) printf("0\n");
  else printf("%d\n", mn);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}