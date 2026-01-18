#include <bits/stdc++.h>
using namespace std;

int a[105], n;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  vector<int> s;
  int lidx = 0;
  for (int i = 0; i < n; i++)
    if (s.empty() || a[s.back()] < a[i]) {
      s.push_back(i), lidx = i;
    } 

  for (int i = lidx+1; i < n; i++)
    if (a[s.back()] == a[i]) {
      s.push_back(i);
      lidx = i;
      break;
    }

  for (int i = lidx+1; i < n; i++) {
    if (a[s.back()] > a[i])
      s.push_back(i);
    else {
      while (!s.empty() && a[s.back()] < a[i]) s.pop_back();
      s.push_back(i);
    }
  }

  for (auto si : s) cout << si+1 << " ";
  cout << "\n";
}
