#include <bits/stdc++.h>
using namespace std;

int n, m, b, a[505][505];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>m>>b;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin>>a[i][j];
  int at = 2000000000, ah;
  for (int h = 256; h >= 0; h--) {
    int t = 0, sum = b;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (a[i][j] > h) {
          t += 2*(a[i][j]-h);
          sum += (a[i][j]-h);
        } else {
          t = t + (h-a[i][j]);
          sum = sum - (h-a[i][j]);
        }
      }
    if (sum >= 0 && at > t) {
      at = t;
      ah = h;
    }
  }
  cout << at << " " << ah << endl;
}
