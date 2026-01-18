#include <stdio.h>
#include <vector>
using namespace std;

int n, m;
vector<vector<int> > a;
int path[2001];

int dfs(int level, int current) {
  if (level >= 4) {
    return 1;
  } else {
    int sum = 0;
    int len = a[current].size();
    for(int i=0; i<len; i++) {
      int next = a[current][i];
      if (path[next] == 0) {
        path[next] = 1;
        sum += dfs(level+1, next);
        path[next] = 0;
      }
    }
    return sum;
  }
}

int main() {
  int i, j;
  int x, y;
  int sum = 0;

  scanf("%d %d", &n, &m);
  a.resize(n+1);
  for(i=0; i<m; i++) {
    scanf("%d %d", &x, &y);
    a[x].push_back(y);
    a[y].push_back(x);
  }

  for (i=0; i<n; i++) {
    path[i] = 1;
    sum += dfs(0, i);
    path[i] = 0;
  }

  printf("%d", sum > 0 ? 1 : 0);
}