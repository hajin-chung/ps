#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
vector<int> parent;
int ans;

bool dfs(int x) {
  if (a[x].size() == 0) return true;

  bool flag = false;
  for (auto next : a[x]) flag |= dfs(next);  
  if (flag) ans++;
  return !flag;
}

int main() {
  int n, i, x, y;
  scanf("%d", &n);
  a.resize(n+1, vector<int>());
  parent.resize(n+1);
  for (i = 0; i < n-1; i++) {
    scanf("%d %d", &x, &y);
    a[x].push_back(y);
    parent[y] = x;
  }
  x = 1;
  while (parent[x]) {
    x = parent[x];
  }
  dfs(x);
  printf("%d\n", ans);
}
