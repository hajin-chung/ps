#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, i, x, parentCnt = 1, ans = 0, cnt = 0;
    scanf("%d", &n);
    vector<int> a(n+1, 0);
    priority_queue<pii> pq;
    for(i=2; i<=n; i++) {
      scanf("%d", &x);
      a[x]++;
      if(a[x] == 1) parentCnt++;
    }
    for(i=1; i<=n; i++) {
      if (a[i] > parentCnt) pq.push({a[i]-parentCnt, 0});
    }
    int timeSpent = parentCnt;
    while(!pq.empty()) {
      pii top = pq.top();
      // printf("%d %d %d %d\n",top.first, top.second, timeSpent, pq.size());
      pq.pop();
      if (top.second != timeSpent) {
        top.first -= (timeSpent - top.second);
        top.second = timeSpent;
        if (top.first > 0) pq.push(top);
      } else {
        top.first --;
        timeSpent++;
        // printf("%d time incr\n", timeSpent);
        top.second = timeSpent;
        if (top.first > 0) pq.push(top);
      }
    }
    printf("%d\n", timeSpent);
  }
}