#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
  int n = rc.size();
  int m = rc[0].size();
  int i, j, t;
  deque<int> fc, lc, fr, lr, tmp;
  deque<deque<int> > a;
  vector<vector<int>> answer;

  for(i=0; i<n; i++) {
    while(!tmp.empty()) tmp.pop_back();
    for(j=0; j<m; j++) {
      if (j == 0) fc.push_back(rc[i][j]);
      else if (j == m-1) lc.push_back(rc[i][j]);
      if (i == 0) fr.push_back(rc[i][j]);
      else if(i == n-1) lr.push_back(rc[i][j]);
      if (0 < i && i < n-1 && 0 < j && j < m-1)
        tmp.push_back(rc[i][j]);
    }
    if (0 < i && i < n-1)
      a.push_back(deque<int>(tmp));
  }

  int on = operations.size();

  for(i=0; i<on; i++) {
    if (operations[i][0] == 'S') { // shift
      tmp = deque<int>(lr);
      lr = deque<int>(fr);
      fr = deque<int>(a.front());

      a.pop_front();
      tmp.pop_back();
      tmp.pop_front();
      a.push_back(tmp);

      fc.push_front(fc.back());
      fc.pop_back();
      lc.push_front(lc.back());
      lc.pop_back();

      fr.push_front(fc.front());
      fr.push_back(lc.front());
      lr.pop_front();
      lr.pop_back();
      lr.push_front(fc.back());
      lr.push_back(lc.back());
    } else { // rotate
      fr.pop_back();
      lc.push_front(fr.back());
      lc.pop_back();
      lr.push_back(lc.back());
      lr.pop_front();
      fc.push_back(lr.front());
      fc.pop_front();
      fr.push_front(fc.front());
    }
  }

  answer.resize(n);
  for(i=0; i<n; i++) {
    if (i == 0) 
      while(!fr.empty()) {
        answer[i].push_back(fr.front());
        fr.pop_front();
      }
    else if (i == n-1) 
      while(!lr.empty()) {
        answer[i].push_back(lr.front());
        lr.pop_front();
      }
    else {
      answer[i].push_back(fc.front());
      tmp = a.front();
      while(!tmp.empty()) {
        answer[i].push_back(tmp.front());
        tmp.pop_front();
      }
      a.pop_front();
      answer[i].push_back(lc.front());
    }
    fc.pop_front();
    lc.pop_front();
  }
  
  return answer;
}