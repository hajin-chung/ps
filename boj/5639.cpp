#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a, s, pre, in;
int idx[1000005];

int u = 0;
void f(int l, int r) {
  if (l == r) {
    cout<<s[l]<<"\n";
    return;
  }
  int i = idx[a[u]];
  if (l <= i-1) {
    u++;
    f(l, i-1);
  }
  if (i+1 <= r) {
    u++;
    f(i+1, r);
  }
  cout<<s[i]<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int x;
  while (cin>>x) a.push_back(x);
  s = a;
  sort(s.begin(), s.end());
  n = s.size();
  for (int i = 0; i < n; i++)
    idx[s[i]] = i;
  f(0, n-1);
}
