#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

const char cc[3] = {'L', 'T', 'I'};
int lu[260];
int cnt[3];

void f() {
  int n; cin>>n;
  string s; cin>>s;
  cnt[0] = cnt[1] = cnt[2] = 0;
  for (int i = 0; i < n; i++) cnt[lu[s[i]]]++;
  int mx = *max_element(cnt, cnt+3);
  if (mx == n) {
    cout<<"-1\n";
    return;
  }

  vector<int> ans;
  for (int i = 1; i < n; i++) {
    ans.push_back((i-1)*3+1);
    ans.push_back((i-1)*3+1);
  }
  ans.push_back((n-1)*3);
  ans.push_back((n-1)*3);
  cout<<sz(ans)<<"\n";
  for (auto x : ans) cout<<x<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  lu['L'] = 0;
  lu['T'] = 1;
  lu['I'] = 2;
  int t; cin>>t;
  while(t--) f();
}
