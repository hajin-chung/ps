#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

queue<int> Q;
vector<vector<int> > a;
vector<int> dist;
vector<int> path;

int main() {
  int n, i;
  int x, y;

  scanf("%d", &n);
  a.resize(n+1);
  dist.resize(n+1);
  for(i=1 ; i<=n-1; i++) {
    scanf("%d %d", &x, &y);
    a[x].push_back(y);
  }
  for(i=1 ; i<=n; i++) {
    scanf("%d", &x);
    path.push_back(x);
  }

  Q.push(1);
  dist[1] = 0;
  while(!Q.empty()) {
    x = Q.front();
    Q.pop();
    int len = a[x].size();
    for(i=0; i<len; i++) {
      y = a[x][i];
      dist[y] = dist[x] + 1;
      Q.push(y);
    }
  }

  int level = 0;
  for(i=0; i<n; i++) {
    if (level != dist[path[i]]) {
      if (level + 1 == dist[path[i]]) {
        level ++;
      } else {
        printf("0");
        return 0;
      }
    }
  }
  printf("1");
}