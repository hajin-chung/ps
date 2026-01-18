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

int a[51][51];

void solve() {
  int n, m;
  int i, j;
  scanf("%d %d", &n, &m);
  for(i=0 ; i<n ; i++) {
    if (i == 0) {
      for(j=0 ; j<m ; j++) {
        if ((j/2+j%2)%2 == 0) printf("0 "), a[i][j] = 0;
        else printf("1 "), a[i][j] = 1;
      }
    } else {
      for(j=0 ; j<m;j++) {
        if ((i/2+i%2)%2 == 0) printf("%d ", a[0][j]);
        else printf("%d ", 1-a[0][j]);
      }
    }
    printf("\n");
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}