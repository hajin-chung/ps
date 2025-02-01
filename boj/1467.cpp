#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t; cin>>s>>t;
  int n = s.size();
  vector<bool> alive(n, 1);
  for (auto c : t) {
    bool flag = 0; int idx = -1, i = 0;
    if (!alive[i]) while (!alive[i] && i<n) i++;
    while (i < n) {
      int k = i++;
      while (!alive[i] && i<n) i++;
      if (s[k] == c) {
        idx = k;
        if (i == n) break;
        if (s[i] > s[k]) {
          alive[k] = 0;
          flag = 1;
          break;
        }       
      }
    }
    if (!flag) {
      alive[idx] = 0;
    }
  }
  for (int i = 0; i < n; i++)
    if (alive[i])
      cout<<s[i];
  cout<<"\n";
}
