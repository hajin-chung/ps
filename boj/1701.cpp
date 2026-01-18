#include <bits/stdc++.h>
using namespace std;

string str;

int solve(string pat) {
  int pi[5000], n, ret = 0;
  n = pat.size();
  memset(pi, 0, sizeof(pi));
  int j = 0;
  for (int i = 1; i < n; i++) {
    while (j > 0 && pat[i] != pat[j]) j = pi[j-1];
    if (pat[i] == pat[j]) pi[i] = ++j;
    ret = max(ret, pi[i]);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int mx = 0;
  cin >> str;
  string pat;
  for (int i = 0; i < str.size(); i++) {
    pat = str.substr(i);
    mx = max(mx, solve(pat));
  }
  printf("%d\n", mx);
}
