#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a[105];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>k;
  for (int i = 0; i < n; i++) {
    int m;
    cin>>m; a[i].resize(m);
    for (auto &aij : a[i]) cin>>aij;
  }

  for (int i = 0; i < n-k; i++)
    for (int j = 0; j < n-k; j++) {
      bool match = true;
      for (int l = 0; l < k; l++)
        if (a[0][i+l] != a[1][j+l]) {
          match = false;
          break;
        }
    }
}
