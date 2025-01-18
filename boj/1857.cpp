#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
const ll INF = LLONG_MAX;
ll dp[905][30][30];
int a[30][30];
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  for (int k = 0; k < 905; k++)
    for (int i = 0; i < 30; i++)
      for (int j = 0; j < 30; j++)
        dp[k][i][j] = INF;
  int n, m; cin>>n>>m;
  pii s, e;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin>>a[i][j];
      if (a[i][j] == 3) s = {i, j};
      if (a[i][j] == 4) e = {i, j};
    }
  dp[0][s.fi][s.se] = 1;
  priority_queue<pip, vector<pip>, greater<pip>> pq;
  pq.push({0, s});
  while (!pq.empty()) {
    auto [k, yx] = pq.top(); pq.pop();
    auto [yy, xx] = yx;
  }
}
