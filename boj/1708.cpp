#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pair<double, double>, pair<int, int> > ppi;

vector<pii> a;
vector<ppi> aa;
stack<ppi> s;
pii p0;

double dist(int x, int y) {
  return sqrt(x*2 + y*2);
}

double angle(int x1, int y1, int x2, int y2) {
  return acos((double)(x1*x2 + y1*y2)/(dist(x1, y1)*dist(x2, y2)));
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
  int cross_product = (x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1);

  if (cross_product > 0){
    return 1;
  }
  else if (cross_product < 0){
    return -1;
  }
  else{
    return 0;
  }
}

int main() {
  int n, x, y;
  int p0Idx;
  int i;

  scanf("%d", &n);
  for(i=0; i<n; i++) {
    scanf("%d %d", &x, &y);
    a.push_back({x, y});

    if (p0.second > y) p0 = {x, y}, p0Idx = i;
    else if (p0.second == y && p0.first > x) p0 = {x, y}, p0Idx = i;
  }

  a.erase(a.begin() + p0Idx);

  for(i=0; i<n; i++) {
    int ang = angle(a[i].first, a[i].second, 1, 0);
    aa.push_back({{ang, dist(a[i].first, a[i].second)}, a[i]});
  }

  sort(aa.begin(), aa.end());


  i = 0;
  while(true) {
    if (i + 1 < aa.size()) {
      if (aa[i+1].first.first == aa[i].first.first) aa.erase(aa.begin() + i);
      else i++;
    } else {
      break;
    }
  }

  int len = aa.size();
  printf("\n");
  for(i=0; i<len; i++) {
    printf("%d %d\n", aa[i].second.first, aa[i].second.second);
  }
  for (i=0; i<len; i++) {
    while (true) {
      if (s.size() <= 1) break;
      ppi t = s.top();
      s.pop();
      ppi tt = s.top();
      s.push(t);

      if (ccw(tt.second.first, tt.second.second, t.second.first, t.second.second, aa[i].second.first, aa[i].second.second)) {
        s.pop();
      }
    }
    s.push(aa[i]);
  }

  printf("%d\n", s.size());
}