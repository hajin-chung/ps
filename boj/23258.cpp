#include <bits/stdc++.h>
using namespace std;

const int N = 300;
const int INF = 1e9;
int a[N+1][N+1], d[N+1][N+1][N+1];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q; cin>>n>>q;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      cin>>d[i][j][0];
      if (d[i][j][0] == 0) d[i][j][0] = INF;
    }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        if (i == j || j == k || k == i) d[i][j][k] = d[i][j][k-1];
        else d[i][j][k] = min(d[i][j][k-1], d[i][k][k-1]+d[k][j][k-1]);
      }
  while (q--) {
    int s, e, c; cin>>c>>s>>e; c--;
    if (s == e) cout<<"0\n";
    else if (d[s][e][c] >= INF) cout<<"-1\n";
    else cout<<d[s][e][c]<<"\n";
  }
}
