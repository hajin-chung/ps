#include <stdio.h>

int t[1025][1025];
int n, m;

int psum(int x, int y) {
  int ret = 0;
  int yy;
  while(x) {
    yy = y;
    while(yy) {
      ret += t[x][yy];
      yy -= yy & -yy;
    }
    x -= (x&-x);
  }
  return ret;
}

int sum(int x1, int y1, int x2, int y2) {
  return psum(x2, y2) - psum(x1-1, y2) - psum(x2, y1-1) + psum(x1-1, y1-1);
}

void update(int x, int y, int val) {
  int dv = val - sum(x, y, x, y);
  int yy;
  while(x <= n) {
    yy = y;
    while(yy <= n) {
      t[x][yy] += dv;
      yy += yy & -yy;
    }
    x += x & -x;
  }
}

int main() {
  int i, j;
  int w, x, y, c, x2, y2;

  scanf("%d %d", &n, &m);  
  for(i=1; i<=n; i++) for(j=1; j<=n; j++) {
    scanf("%d", &x);
    update(i, j, x);
  }

  for(i=1; i<=m; i++) {
    scanf("%d", &w);
    if (w == 0) {
      scanf("%d %d %d", &x, &y, &c);
      update(x, y, c);
    } else {
      scanf("%d %d %d %d", &x,&y, &x2, &y2); 
      printf("%d\n", sum(x, y, x2, y2));
    }
  }
} 