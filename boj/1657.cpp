#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int N = 14;
int s[5][5] = {{10, 8, 7, 5, 1}, {8, 6, 4, 3, 1}, {7, 4, 3, 2, 1}, {5, 3, 2, 2, 1}, {1, 1, 1, 1, 0}};
int a[N][N];
int dp[2][1<<N];

void mx(int &x, int v) { x = max(x, v); }

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin>>n>>m;
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < m; j++) {
      char c; cin>>c;
      a[i][j] = c-'A';
    }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int k = i&1;
    for (int bit = 0; bit < (1<<m); bit++) {
      for (int j = 0; j < m; j++) {
        if (bit & (1<<j)) 
          mx(dp[k][bit], dp[k][bit&~(1<<j)]);
        if (j > 0 && (bit & ((1<<j)|(1<<(j-1))))) {
          int b = bit&~((1<<j)|(1<<(j-1)));
          mx(dp[k][bit], dp[k][b]+s[a[i][j]][a[i][j-1]]);
        }
        if (i > 0 && (bit & (1<<j))) {
          int b2 = ((1<<m)-1)&~(1<<j), b1 = bit&~(1<<j);
          mx(dp[k][bit], dp[k][b1]+dp[1-k][b2]+s[a[i][j]][a[i-1][j]]);
        }
      }
      mx(ans, dp[k][bit]);
    }
  }
  cout<<ans<<"\n";
}
