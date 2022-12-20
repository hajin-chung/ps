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
  int n, cnt = 0, last = 0;
  int ans = 0;
  scanf("%d", &n);
  while(n) {
    last = n%10;
    cnt++;
    n/=10;
  }
  for(int i=1 ; i<cnt ; i++) ans += 9;
  ans += last;
  printf("%d\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}