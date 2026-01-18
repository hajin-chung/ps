#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> a;

bool cmp(string a, string b) {
  return a + b > b + a;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n; a.resize(n);
  bool zflag = true;
  for (int i = 0; i < n; i++) {
    cin>>a[i];
    if (a[i] != "0") zflag = false;
  }
  if (zflag) {
    cout << "0\n";
    return 0;
  }
  sort(a.begin(), a.end(), cmp);
  for (int i = 0; i < n; i++)
    cout<<a[i];
  cout<<"\n";
}
