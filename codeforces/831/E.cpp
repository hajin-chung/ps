#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int> > a;

int dp(int idx) {
  int i, len = a[idx].size(), sum = 0;

  if (len == 0) return 1;
  else {
    for(i=0; i<len ; i++)
      sum += dp(a[idx][i]);
    return sum + 1;
  }
}

int main() {
  int i, x;

  scanf("%d", &n);
  a.resize(n+1);
  for(i=2; i<=n; i++) {
    scanf("%d", &x);
    a[x].push_back(i);
  }

  printf("%d\n", dp(1));
}