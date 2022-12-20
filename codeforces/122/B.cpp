#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <deque>
#include <stack>
#include <string.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

void solve() {
  int zc, oc, i;
  zc = oc = 0;
  char a[200006];
  for(i=0 ; i<200006; i++) a[i] = 0;
  scanf("%s", &a[1]);
  int len = strlen(&a[1]);
  for(i=1;  i<=len; i++) {
    if (a[i] == '0') zc++;
    else oc++;
  }

  if (zc < oc) printf("%d\n", zc);
  else if (zc > oc) printf("%d\n", oc);
  else printf("%d\n", zc-1);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}