#include <bits/stdc++.h>
using namespace std;

priority_queue<int> SQ;
priority_queue<int, vector<int>, greater<int> > LQ;

int main() {
  int n, i, x;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &x);
    if (SQ.empty()) {
      SQ.push(x);
      printf("%d\n", SQ.top());
      continue;
    } 

    if (SQ.size() == LQ.size()) {
      SQ.push(x);
    } else {
      if (x <= SQ.top()) {
        LQ.push(SQ.top());
        SQ.pop();
        SQ.push(x);
      } else {
        LQ.push(x);
      }
    }

    printf("%d\n", SQ.top());
  }
}
