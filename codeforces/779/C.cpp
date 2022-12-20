#include <stdio.h>
#include <vector>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, flag = 1, cnt = 0, i, s;
    scanf("%d", &n);
    vector<int> a(n, 0);
    for(i=0 ; i<n; i++) {
      scanf("%d", &a[i]);
      if (a[i] == 1) {
        cnt++;
        s = i;
      }
    }

    if (cnt != 1) flag = 0;
    for(i=0; i<n; i++) {
      int idx = (s+i) % n;
      if (a[(idx+1)%n] - a[idx] >= 2) flag = 0; 
    }
    
    if (flag == 0) printf("NO\n");
    else printf("YES\n");
  }
}