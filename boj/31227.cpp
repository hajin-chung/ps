#include <bits/stdc++.h>
#define INF 2000000000
#define N 3000
using namespace std;

typedef long long int ll;
struct pt {ll x, y;};
int n, m;
ll dp[N+1], R[N+1][N+1];
vector<pt> a;

ll dist(pt a, pt b) { return abs(a.x-b.x)+abs(a.y-b.y); }

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>m>>n; a.resize(n+1);
  for (int i = 1; i <= n; i++) cin>>a[i].x>>a[i].y;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      R[i][j] = INF;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)

}
