#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
  vector<int> dist;
  vector<int> answer;
  vector<int> isSummit;
  priority_queue<pii, vector<pii>, greater<pii>> Q;
  vector<vector<pii>> a;
  int gates_N = gates.size();
  int i, j, len;
  pii yy, ty, ans;

  dist.resize(n+1, 10000001);
  a.resize(n+1);
  isSummit.resize(n+1, 0);

  len = paths.size();
  for(i=0; i<len; i++) {
    a[paths[i][0]].push_back({paths[i][1], paths[i][2]});
    a[paths[i][1]].push_back({paths[i][0], paths[i][2]});
  }

  len = summits.size();
  for(i=0; i<len; i++) {
    isSummit[summits[i]] = 1;
  }

  for(i=0; i<gates_N; i++) {
    Q.push({0, gates[i]});
    dist[gates[i]] = 0;
    while(!Q.empty()) {
      yy = Q.top();
      Q.pop();
      int len = a[yy.second].size();
      for(j=0; j<len; j++) {
        ty = a[yy.second][j];
        if (dist[ty.first] > max(dist[yy.second], ty.second)) {
          dist[ty.first] = max(dist[yy.second], ty.second);
          if (isSummit[ty.first] == 0)
            Q.push({dist[ty.first], ty.first});
        }
      }
    }
  }

  len = summits.size();
  ans = {10000001, 50001};
  for(i=0; i<len; i++) {
    ans = min(ans, {dist[summits[i]], summits[i]});
  }

  answer.push_back(ans.second);
  answer.push_back(ans.first);

  return answer;
}