#include <bits/stdc++.h>
#define N 1000000
using namespace std;

int n, lookup[N+1], dp[N+1], x;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  int lis = 1;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    lookup[x] = i;
    if (lookup[x-1]) {
      dp[x] = dp[x-1] + 1;
      lis = max(lis, dp[x])+1;
    }
  }
  cout << n-lis << "\n";
}
