#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int lc[55][55][55][55], rc[55][55];

int f(int h, int w) {
  if (rc[h][w]) return rc[h][w];
  int mn = INF;
  for (int i = 1; i < h; i++)
    mn = min(mn, f(i, w)+f(h-i, w));
  for (int i = 1; i < w; i++)
    mn = min(mn, f(h, i)+f(h, w-i));
  return rc[h][w] = mn;
}

int f(int h1, int w1, int h2, int w2) {
  if (lc[h1][w1][h2][w2]) return lc[h1][w1][h2][w2];
  int mn = INF;
  for (int i = 1; i < h2; i++)
    mn = min(mn, f(i, w1-w2)+f(h1-i, w1, h2-i, w2));
  mn = min(mn, f(h2, w1-w2)+f(h1-h2, w1));
  for (int i = h2+1; i < h1; i++)
    mn = min(mn, f(i, w1, h2, w2)+f(h1-i, w1));
  for (int i = 1; i < w2; i++)
    mn = min(mn, f(h1-h2, i)+f(h1, w1-i, h2, w2-i));
  mn = min(mn, f(h1, w1-w2)+f(h1-h2, w2));
  for (int i = w2+1; i < w1; i++)
    mn = min(mn, f(h1, i, h2, w2)+f(h1, w1-i));
  return lc[h1][w1][h2][w2] = mn;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h1, w1, h2, w2; cin>>h1>>w1>>h2>>w2;
  for (int i = 1; i <= 50; i++) rc[i][i] = 1;
  cout<<f(h1, w1, h2, w2)<<"\n";
}
