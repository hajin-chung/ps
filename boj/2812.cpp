#include <bits/stdc++.h>
using namespace std;

bool comp(pair<char, int> a, pair<char, int> b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k; cin>>n>>k;
  string a; cin>>a;
  vector<pair<char, int>> fi;
  for (int i = 0; i <= k; i++)
    fi.push_back({a[i], i});
  sort(fi.begin(), fi.end());
  int cut = 0;
  for (int i = k-1; i >= 0; i--) {
    if (fi[i] != fi[i+1]) {
      cut = i;
      break;
    }
  }

}
