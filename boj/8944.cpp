#include <bits/stdc++.h>
#define MOD 9999991
using namespace std;

typedef long long int ll;
ll bi[21][21];
vector<int> a;

ll rec(vector<int> &v) {
  if (v.size() == 0 || v.size() == 1) return 1;
  vector<int> st, bt; 
  for (int i = 1; i < v.size(); i++) {
    if (v[i] > v[0]) bt.push_back(v[i]);
    else st.push_back(v[i]);
  }
  return bi[v.size()-1][st.size()]*rec(st)*rec(bt);
}

void solve() {
  int n; cin>>n;
  a.clear(); a.resize(n);
  for (auto &ai : a) cin>>ai;
  cout<<rec(a)<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  bi[0][0] = 1;
  for (int i = 1; i <= 20; i++) {
    bi[i][0] = 1;
    for (int j = 1; j <= i; j++)
      bi[i][j] = (bi[i-1][j] + bi[i-1][j-1])%MOD;
  }
  int t; cin>>t;
  while (t--) solve();
}
