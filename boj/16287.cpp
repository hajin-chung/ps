#include <bits/stdc++.h>
using namespace std;

typedef map<int, bool> uib;

uib rmp;
vector<uib> mp;
vector<int> weights;
int n, goal;

void print(uib m) {
  for (auto [i, b] : m) printf("%d ", i);
  printf("\n");
}

int main() {
  scanf("%d %d", &goal, &n);
  for (int i = 0; i < n; i++) {
    int w;
    scanf("%d", &w);
    weights.push_back(w);
  }
  mp.resize(n);
  for (int i = 1 ; i < n; i++) 
    for (int j = 0; j < i; j++) {
      int sum = weights[i] + weights[j];
      mp[i][sum] = true;
    }

  for (int i = 2; i < n; i++) {
    rmp.merge(mp[i-1]);
    /*printf("%d\n", i);*/
    /*print(rmp);*/
    for (int j = i+1; j < n; j++) {
      int sum = weights[i] + weights[j];
      if (rmp.count(goal-sum)) {
        printf("YES\n");
        return 0;
      }
    }
  }

  printf("NO\n");
  return 0;
}
