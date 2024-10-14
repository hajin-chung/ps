#include <bits/stdc++.h>
using namespace std;

bool solve() {
  string p;
  cin >> p;
  if (p[0] == '.') return false;

  vector<int> dp;
  int n = p.size();
  dp.resize(n);
  int i, j;
  i = 1, j = 0;
  while (i < n) {
    if (p[i] == p[j]) {
      dp[i] = j+1;
      i++;
      j++;
    } else if (j > 0) {
      j = dp[j-1];
    } else {
      dp[j] = 0;
      i++;
    }
  }
  printf("%d\n", n/(n-dp[n-1]));
  return true;
}

int main() {
  while(solve()){}
}
