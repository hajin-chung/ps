#include <bits/stdc++.h>
using namespace std;

int main() {
  while (true) {
    string line;
    getline(cin, line);
    if (line.size() == 1 && line[0] == '.') break;
    stack<char> s;
    bool flag = true;
    for (auto c : line) {
      if (c == '(') s.push('(');
      else if (c == ')') {
        if (s.empty()) flag = false;
        else if (s.top() != '(') flag = false;
        else s.pop();
      }
      else if (c == '[') s.push('[');
      else if (c == ']') {
        if (s.empty()) flag = false;
        else if (s.top() != '[') flag = false;
        else s.pop();
      }
    }
    if (s.empty() && flag) cout << "yes\n";
    else cout << "no\n";
  }
}
