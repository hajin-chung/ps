#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void f() {
  int n; cin>>n;
  vector<int> c(2*n+1);
  vector<vector<int>> gs(1);
  int si = 0;
  for (int i = 1; i <= 2*n; i++) {
    cin>>c[i];
    if (i == 1) si = i;
    else if (c[si] < c[i]) {
      vector<int> g;
      for (int j = si; j < i; j++)
        g.push_back(c[j]);
      gs.push_back(g);
      si = i;
    }
  }
  vector<int> g;
  for (int j = si; j <= 2*n; j++)
    g.push_back(c[j]);
  gs.push_back(g);

  vector<int> dp(n+1);
  for (int j = 1; j < sz(gs); j++) {
    for (int i = n; i > sz(gs[j]); i--)
      if (dp[i-sz(gs[j])] && dp[i] == 0)
        dp[i] = j;
    if (!dp[sz(gs[j])]) dp[sz(gs[j])] = j;
  }

  if (dp[n] == 0) {
    cout<<"-1\n";
    return;
  }

  set<int> a, b;
  si = n;
  while (si) {
    a.insert(dp[si]);
    si -= sz(gs[dp[si]]);
  }
  for (int i = 0; i < sz(gs); i++)
    if (a.count(i) == 0)
      b.insert(i);

  for (auto i : a)
    for (auto v : gs[i])
      cout<<v<<" ";
  cout<<"\n";
  for (auto i : b)
    for (auto v : gs[i])
      cout<<v<<" ";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  f();
}
