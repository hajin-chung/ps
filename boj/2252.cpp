#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> indegree;
vector<vector<int>> a;
queue<int> Q;

int main() {
  int i, j, x, y;
  scanf("%d %d", &n, &m);
  a.resize(n, vector<int>());
  indegree.resize(n);
  for (i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    x--, y--;
    a[x].push_back(y); 
    indegree[y]++;
  }
  for (i = 0; i < n; i++) if (indegree[i] == 0) Q.push(i);
  while(!Q.empty()) {
    int f = Q.front();
    Q.pop();
    printf("%d ", f+1);
    for (auto c : a[f]) if (--indegree[c] == 0) Q.push(c);
  }
  printf("\n");
}
