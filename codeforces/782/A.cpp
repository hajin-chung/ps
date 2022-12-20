#include <stdio.h>
#include <math.h>
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
  int n, r, b;  
  int i, j;
  int cnt = 0;
  scanf("%d %d %d", &n, &r, &b);
  for(i=1 ; i<=b;i++) {
    int m = r/(b+1);
    if (r-(b+1)*(int)(r/(b+1)) >= i) m++;
    for(j=1 ; j<=m ; j++) printf("R"), cnt++;
    printf("B"), cnt++;
  }
  for(i=1;  i<=n-cnt; i++) printf("R");
  printf("\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}