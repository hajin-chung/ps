#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#define INF 100000000
#define MAX_N 150

using namespace std;

typedef pair<int, pair<int, int>> pii;

int solution(int alp, int cop, vector<vector<int>> problems) {
  int i, j;
  int answer = INF;
  int problems_N;
  int mxa, mxc;
  pii t;
  int yy, xx, ty, tx, dd, td;
  priority_queue<pii, vector<pii>, greater<pii>> Q;
  map<pair<int, int>, bool> m;
  mxa = mxc = 0;

  problems.push_back(vector<int>{0, 0, 0, 1, 1});
  problems.push_back(vector<int>{0, 0, 1, 0, 1});
  problems_N = problems.size();

  for(i=0; i<problems_N; i++) {
    mxa = max(mxa, problems[i][0]);
    mxc = max(mxc, problems[i][1]);
  }

  Q.push({0, {alp, cop}});
  while(!Q.empty()) {
    yy = Q.top().second.first;
    xx = Q.top().second.second;
    dd = Q.top().first;
    Q.pop();

    if (m[{yy, xx}]) continue;
    m[{yy, xx}] = true;

    if (yy >= mxa && tx >= mxc) {
      answer = dd;
      break;
    }

    for(i=0; i<problems_N; i++) {
      ty = yy + problems[i][2];
      tx = xx + problems[i][3];
      td = dd + problems[i][4];
      if (yy>= problems[i][0] && xx>= problems[i][1]) {
        Q.push({td, {ty, tx}});
      }
    }
  }

  return answer;
}