#include <bits/stdc++.h>
#define N 10000
using namespace std;

int dp[N+1];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  for (int i = 1; i <= N; i++) 
    for (int j = i; j >= 0; j-=3)
      dp[i] += 1+j/2;
  int m, t;
  cin >> m;
  while (m--) {
    cin >> t;
    cout << dp[t] << "\n";
  }
}
