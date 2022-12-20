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
  scanf("%d", &n);
  if (n%2 == 0) {
    for(i=n/2 ; i>=1 ; i--) printf("%d %d ", i, i+n/2);
  } else {
    for(i=(n+1)/2 ; i>=2 ; i--) printf("%d %d ", i, i+n/2);
    printf("1");
  }
  printf("\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}