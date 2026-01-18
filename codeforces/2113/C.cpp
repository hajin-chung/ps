#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

const int N = 500;
int a[N+1][N+1], gsum[2*N+1][2*N+1];

int sum(int y, int x, int k) {
  int sy = max(0, y-k), sx = max(0, x-k);
  return gsum[y][x] - gsum[sy][x] - gsum[y][sx] + gsum[sy][sx];
}

void f() {
  int n, m, k; cin>>n>>m>>k;
  int gcnt = 0;
  for (int i = 1; i <= n; i++) {
    string s; cin>>s;
    for (int j = 1; j <= m; j++) {
      if (s[j-1] == '#') a[i][j] = 1;
      else if (s[j-1] == 'g') {
        a[i][j] = 2;
        gcnt++;
      }
      else a[i][j] = 0;
    }
  }

  for (int i = 1; i <= n+k; i++) {
    for (int j = 1; j <= m+k; j++) {
      if (i <= n && j <= m) gsum[i][j] = gsum[i-1][j]+gsum[i][j-1]-gsum[i-1][j-1]+(a[i][j] == 2);
      else gsum[i][j] = gsum[i-1][j]+gsum[i][j-1]-gsum[i-1][j-1];
    }
  }

  int mn = gcnt;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      if (a[i][j] == 0)
        mn = min(mn, sum(i+k-1, j+k-1, 2*k-1));
  }
  cout<<gcnt-mn<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
