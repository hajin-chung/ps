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
  vector<pii> a(3, {0, 0});
  int i;
  for(i=0 ; i<3 ; i++) scanf("%d %d", &a[i].first, &a[i].second);
  if (a[0].first == a[1].first && (a[1].second == a[2].second || a[0].second == a[2].second)) {
    printf("NO\n");
    return;
  }
  if (a[1].first == a[2].first && (a[2].second == a[0].second || a[1].second == a[0].second)) {
    printf("NO\n");
    return;
  }
  if (a[2].first == a[0].first && (a[0].second == a[1].second || a[2].second == a[1].second)) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}