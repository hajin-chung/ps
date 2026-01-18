#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> a;
map<string, int> lookup;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m; a.resize(n+1);
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    a[i] = s;
    lookup[s] = i;
  }

  while (m--) {
    string s;
    cin >> s;
    if ('0' <= s[0] && s[0] <= '9') {
      int idx = stoi(s);
      cout << a[idx] << "\n";
    } else {
      cout << lookup[s] << "\n";
    }
  }
}
