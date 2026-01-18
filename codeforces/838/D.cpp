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
  int n, mx = 0, i;
  int a, b, l ,r;
  scanf("%d", &n);

  a = 1, b = 2;
  for(i=3 ; i<=n ; i++) {
    printf("? %d %d\n", a, i);
    fflush(stdout);
    scanf("%d", &l);
    printf("? %d %d\n", b, i);
    fflush(stdout);
    scanf("%d", &r);
    if (l > r) b = i;
    else if (l < r) a = i; 
  } 
  printf("! %d %d\n", a, b);
  fflush(stdout);


  int t;
  scanf("%d", &t);
  if (t == -1) exit(0);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}