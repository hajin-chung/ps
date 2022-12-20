#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int sum[100005];
int msum[100005];
int a[100005];

int main() {
  int i;

  scanf("%d",  &n);
  for(i=1; i<=n; i++) {
    scanf("%d", &a[i]);
    sum[i] = sum[i-1] + a[i];
    msum[i] = min(msum[i-1], sum[i-1]);
  }

  // sum from a to b = s[b] - s[a-1];
  // maximize sum to b => find minimum of s[a-1];
}