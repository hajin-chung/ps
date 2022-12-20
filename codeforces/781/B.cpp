#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, x, i;
    int mx = 0, target, cnt = 0, coverage = 0;
    scanf("%d",&n);
    map<int, int> mp;
    for(i=0 ; i<n; i++) {
      scanf("%d", &x);
      mp[x]++;
      if (mp[x] > mx) {
        mx = mp[x];
        target = x;
      }
    } 
    coverage = mx;
    while(coverage < n) {
      cnt++;
      if (coverage >= n) {
        cnt += (n-coverage/2);
        break;
      }
      cnt += coverage;
      coverage *= 2;
    }
    cnt += (n - coverage);

    printf("%d\n", cnt);
  }
}