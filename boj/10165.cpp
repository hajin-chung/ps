/*
 * 1 -10 -6
 * 2 -8 -4
 * 3 -5 0
 * 4 -3 -1
 * 5 -1 4
 * 1 0 4
 * 2 2 6
 * 4 7 9
*/

#include <bits/stdc++.h>
using namespace std;

struct B {
  int idx, s, e;
};

bool comp(B &a, B &b) {
  if (a.s == b.s) return a.e > b.e;
  return a.s < b.s;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int m, n; cin>>m>>n;
  vector<B> a(n);
  vector<bool> chk(n, true);
  for (int i = 0; i < n; i++) {
    a[i].idx = i;
    cin>>a[i].s>>a[i].e;
    if (a[i].s > a[i].e) {
      a[i].s -= m;
    } else {
      a.push_back({i, a[i].s-m, a[i].e-m});
    }
  }
  sort(a.begin(), a.end(), comp);
  for (int i = 0; i < a.size();) {
    B b = a[i];
    while (++i < a.size() && b.s <= a[i].s && a[i].e <= b.e) 
      chk[a[i].idx] = false;
  }
  for (int i = 0; i < n; i++)
    if (chk[i])
      cout<<i+1<<" ";
  cout<<"\n";
}
