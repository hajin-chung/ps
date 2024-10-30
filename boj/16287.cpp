#include <bits/stdc++.h>
using namespace std;

int target, n;
pair<int, int> m[400005];
vector<int> a;

int main() {
  scanf("%d%d", &target, &n);
  a.resize(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++)
      m[a[i]+a[j]] = {i+1, j+1};
  for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++) {
      int sum = target - (a[i]+a[j]);
      if (sum < 0) continue;
      if (m[sum].first == 0) continue;
      if (m[sum].first != i+1 
          && m[sum].first != j+1
          && m[sum].second != i+1
          && m[sum].second != j+1) {
        printf("YES\n");
        return 0;
      }
    }
  printf("NO\n");
  return 0;
}
