#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int dist(int y1, int x1, int y2, int x2) {
  return abs(y2-y1)+abs(x2-x1);
}

int max(int a, int b) {
  return a > b ? a : b;
}

int min(int a, int b) {
  return a < b ? a : b;
}

int main() {
  int n, k, mx = 0, mx2 = 0, yy, xx, yy2, xx2;
  int i, j;

  scanf("%d %d", &n, &k);
  vector<vector<int> > a(n+1, vector<int>(n+1, 0));
  for(i=1 ; i<=n; i++) {
    for(j=1 ; j<=n ; j++) {
      scanf("%d", &a[i][j]);
      if (mx < a[i][j]) {
        mx = a[i][j];
        yy = i;
        xx = j;
      }
    }
  }

  for(i=1 ; i<=n; i++)
    for(j=1; j<=n; j++) {
      int d = dist(i, j, yy, xx);
      if (d != 0 && d <= k && a[i][j] > mx2) {
        mx2 = a[i][j];
        yy2 = i;
        xx2 = j;
      }
    }
  
  for(i=1 ; i<=n; i++) {
    for(j=1 ; j<=n; j++) {
      if (min(yy, yy2) <= i && i <= max(yy, yy2) && min(xx, xx2) <= j && j <=max(xx, xx2)) printf("M");
      else printf("G");
    }
    printf("\n");
  }
}