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
  int n, i, j;
  char c[105];
  int a[105][105];
  scanf("%d", &n);
  vector<vector<int> > ans(n+1, vector<int>(0));
  for(i=1 ; i<=n ; i++) {
    ans[i].push_back(i);
    for(j=1 ; j<=104 ; j++) c[j] = 0;
    scanf("%s", &c[1]);
    for(j=1 ; j<=n ; j++) {
      if (c[j] - '0' == 1) {
        ans[j].push_back(i);
      }
    }
  }

  for(i=1 ; i<=n ; i++) {
    printf("%d ", ans[i].size());
    for(j=0 ; j<ans[i].size() ; j++) {
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }

}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}