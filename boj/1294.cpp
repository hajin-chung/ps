#include <bits/stdc++.h>
using namespace std;

struct comp {
  bool operator()(string &a, string &b) {
    return a+b > b+a;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, len = 0; cin>>n;
  priority_queue<string, vector<string>, comp> pq;
  for (int i = 0; i < n; i++) {
    string s; cin>>s;
    pq.push(s); len += s.size();
  }
  while (len--) {
    string s = pq.top(); pq.pop();
    cout<<s[0];
    if (s.size() != 1) pq.push(s.substr(1));
  }
  cout<<"\n";
}
