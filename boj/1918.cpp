#include <bits/stdc++.h>
using namespace std;

int prec(char c) {
  if (c == '/' || c == '*') return 2;
  else if (c == '+' || c == '-') return 1;
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string eq, ans;
  stack<char> s;
  cin >> eq;

  for (int i = 0; i < eq.size(); i++) {
    char c = eq[i];
    if (c >= 'A' && c <= 'Z') {
      ans.push_back(c);
    } else if (c == '(') {
      s.push(c);
    } else if (c == ')') {
      while (!s.empty() && s.top() != '(') {
        char ss = s.top();
        s.pop();
        if (ss != ')' && ss != '(') ans.push_back(ss);
      }
      if (!s.empty()) s.pop();
    } else {
      while (!s.empty() && (prec(c) <= prec(s.top()))) {
        ans.push_back(s.top());
        s.pop();
      }
      s.push(c);
    }
  }

  while (!s.empty()) {
    ans.push_back(s.top());
    s.pop();
  }

  cout << ans << "\n";
}
