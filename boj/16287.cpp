#include <bits/stdc++.h>
using namespace std;

int target, n;
pair<int, int> m[400000];
vector<int> a;

int main() {
  scanf("%d%d", &target, &n);
  a.resize(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++)
      m[a[i]+a[j]] = {i, j};
  for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++) {
      int sum = target - (a[i]+a[j]);
      if (m[sum].first != i 
          && m[sum].first != j 
          && m[sum].second != i 
          && m[sum].second != j) {
        printf("YES\n");
        return 0;
      }
    }
  printf("NO\n");
  return 0;
}
