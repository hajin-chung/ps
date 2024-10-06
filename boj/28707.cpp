#include <bits/stdc++.h>
using namespace std;

typedef pair<int, vector<int>> T;

int n, m, a[10][3];

bool is_sorted(vector<int> &a) {
  for (int i = 1; i < a.size(); i++) if (a[i] < a[i-1]) return false;
  return true;
}

int main() {
  int i;
  vector<int> s;
  scanf("%d", &n);
  s.resize(n);
  for (i = 0; i < n; i++) scanf("%d", &s[i]);
  scanf("%d", &m);
  for (i = 0; i < m; i++) scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
  set<vector<int>> vis;
  priority_queue<T, vector<T>, greater<T>> Q;
  Q.push({0, s});
  while (!Q.empty()) {
    T f = Q.top();    
    Q.pop();
    if (vis.count(f.second)) continue;
    vis.emplace(f.second);
    if (is_sorted(f.second)) {
      printf("%d\n", f.first);
      return 0;
    }
    for (i = 0; i < m; i++) {
      vector<int> t = f.second;
      int tmp = t[a[i][0] - 1];
      t[a[i][0] - 1] = t[a[i][1] - 1];
      t[a[i][1] - 1] = tmp;
      Q.push({f.first + a[i][2], t});
    }
  }
  printf("-1\n");
  return 0;
}
