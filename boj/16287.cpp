#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> mp;
vector<int> weights;
int n, sum;

int main() {
  scanf("%d %d", &sum, &n);
  for (int i = 0; i < n; i++) {
    int w;
    scanf("%d", &w);
    weights.push_back(w);
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++) {
      if (mp[sum - (weights[i]+weights[j])]) {
        printf("YES\n");
        return 0;
      }
      mp[weights[i]+weights[j]] = 1;
    }
  printf("NO\n");
  return 0;
}
