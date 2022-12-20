#include <stdio.h>
#include <algorithm>
using namespace std;

char s[100005];
int d[100005][10];
int tmp[10];

int main() {
  int t, n;
  int i, j, k;
  int cnt;
  scanf("%d", &t);
  while(t--) {
    cnt = 0;

    scanf("%d", &n);
    for(i=0; i<=n+1; i++) {
      s[i] = 0;
      for(j=0; j<10; j++) d[i][j] = 0;
    }
    
    scanf("%s", &s[1]);
    for(i=1 ; i<=n; i++) {
      for(j=0; j<10; j++) d[i][j] = d[i-1][j];
      d[i][s[i]-'0']++;

      for(j=i; j>max(i-100, 0); j--) {
        int diverse = 0, mx = 0;
        for(k=0; k<10; k++) {
          tmp[k] = d[i][k] - d[j-1][k];
          mx = max(mx, tmp[k]);
          if (tmp[k] != 0) diverse++;
        }

        if (diverse >= mx) cnt++;
      }
    }
    printf("%d\n", cnt);
  }
}