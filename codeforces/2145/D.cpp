#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

const int N = 500;
int dp[N+1][N*(N-1)/2+5], inv[N+1], ans[N+1];

void f() {
  int n, k; cin>>n>>k;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n*(n-1)/2; j++)
      dp[i][j] = -1;
  for (int i = 1; i <= n; i++) inv[i] = 0;
  dp[1][0] = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      for (int c = 0; c <= n*(n-1)/2; c++) {
        if (dp[j][c] != -1) {
          dp[i][c+(n-i+1)*(i-j)] = j;
        }
      }
    }
  }
  int curr = -1, next;
  for (int i = 1; i <= n; i++)
    if (dp[i][k] >= 0)
      curr = i;
  if (curr == -1) {
    cout<<"0\n";
    return;
  }
  while (curr > 1) {
    inv[curr] = 1;
    next = dp[curr][k];
    k -= (n-curr+1)*(curr-next);
    curr = next;
  }
  int v = 1;
  for (int i = n; i >= 1; i--)
    if (inv[i])
      ans[i] = v++;
  for (int i = 1; i <= n; i++)
    if (!inv[i])
      ans[i] = v++;
  for (int i = 1; i<= n; i++)
    cout<<ans[i]<<" ";
  cout<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
