#include <bits/stdc++.h>
#define N 6144
using namespace std;

bool a[N+1][N+1];
int w = 0, h = 0;

void rec(int lev, int y, int x) {
  if (lev == 0) {
    a[y][x] = a[y+1][x-1] = a[y+1][x+1] = 1;
    for (int i = 0; i < 5; i++)
      a[y+2][x-2+i] = 1;
    h = max(h, y+2);
    w = max(w, x+2);
    return;
  }
  rec(lev-1, y, x);
  int k = 1<<(lev-1);
  rec(lev-1, y+3*k, x-3*k);
  rec(lev-1, y+3*k, x+3*k);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, t = 1, k = 0; cin>>n;
  n/=3;
  while (t != n) {
    t *= 2;
    k++;
  }
  int x = 2;
  if (k > 0) x = 6*(1<<(k-1))-1;
  rec(k, 0, x);
  for (int i = 0; i <= h; i++) {
    for (int j = 0; j <= w; j++) {
      if (a[i][j]) cout<<"*";
      else cout<<" ";
    }
    cout<<"\n";
  }
}
