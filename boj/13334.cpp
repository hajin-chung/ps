#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> a;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
  cin.tie(0)->sync_with_stdio(false), cout.tie(0);
  int n, d, x, y, i, ans = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &x, &y);
    if (x > y) a.push_back({x, y});
    else a.push_back({y, x});
  }
  scanf("%d", &d);
  sort(a.begin(), a.end());
  for (i = 0; i < n; i++) {
    if (a[i].first - a[i].second > d) continue;
    pq.push(a[i].second);
    while(!pq.empty() && pq.top() < a[i].first - d) pq.pop();
    ans = max(ans, (int)pq.size());
  }
  printf("%d\n", ans);
}
