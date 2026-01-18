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
  if (n % 2 == 1) {
    int x;
    while(n--) scanf("%d", &x);
    printf("-1\n");
    return;
  }
  
  vector<pii> ans;
  for(i=1 ; i<=n ; i+=2) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x == y) ans.push_back({i, i+1});
    else ans.push_back({i, i}), ans.push_back({i+1, i+1});
  }
  int len = ans.size();
  printf("%d\n", len);
  for(i=0;i<len;i++)printf("%d %d\n", ans[i].first, ans[i].second);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}