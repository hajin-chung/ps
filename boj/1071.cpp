#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int x; cin>>n;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n; i++) {
    cin>>x;
    pq.push(x);
  }
  vector<int> ans;
  int f = pq.top(); pq.pop();
  ans.push_back(f);
  while (!pq.empty()) {
    int f = ans.back();
    int s = pq.top(); pq.pop();
    if (f+1 == s) {
      if (pq.empty()) {
        int f = ans.back(); ans.pop_back();
        ans.push_back(s);
        ans.push_back(f);
        continue;
      } else {
        int t = pq.top(); pq.pop();
        ans.push_back(t);
      }
    }
    ans.push_back(s);
  }
  for (auto i : ans) 
    cout<<i<<" ";
  cout<<"\n";
}
