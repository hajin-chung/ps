#include <bits/stdc++.h>
using namespace std;

vector<string> a;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n, i, j, k, m;
  string x;
  cin >> n;
  a.resize(n);
  for (i = 0; i < n; i++) {
    cin >> m;
    for (j = 0; j < m; j++) {
      cin >> x;
      if (j != 0) a[i] += "/" + x;
      else a[i] = x;
    }
  }
  sort(a.begin(), a.end());
  x = "";
  for (i = 0; i < n; i++) {
    int cnt = 0, last = 0;
    for (j = 0; j < min(x.size(), a[i].size()); j++) {
      if (x[j] != a[i][j]) break;
      if (x[j] == '/') {
        cnt++;
        last = j;
      }
    }
    for (k = 0; k < cnt; k++) cout << "--";
    for (j = last == 0 ? 0 : last+1; j < a[i].size(); j++) {
      if (a[i][j] == '/') {
        cout << "\n";
        cnt++;
        for (k = 0; k < cnt; k++) cout << "--";
      } else {
        cout << a[i][j];
      }
    }
    x = a[i];
    cout << "\n";
  }
}
