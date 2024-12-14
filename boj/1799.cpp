#include <bits/stdc++.h>
using namespace std;

int n, ans[2], c, a[10][10], l[33], r[33];

void rec(int y, int x, int cnt) {
  ans[c] = max(ans[c], cnt);
  if (x >= n) {
    y++;
    x = (c == 0) ? (y%2) : (1-y%2);
  }
  if (y == n) return;
  if (a[y][x] && !l[y+x] && !r[y-x+n]) {
    l[y+x] = r[y-x+n] = 1;
    rec(y, x+2, cnt+1);
    l[y+x] = r[y-x+n] = 0;
  }
  rec(y, x+2, cnt);
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin>>a[i][j];
  rec(0, 0, 0); c = 1;
  rec(0, 1, 0);
  cout<<ans[0]+ans[1]<<"\n";
}
