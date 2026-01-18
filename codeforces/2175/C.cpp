#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
const int N = 26;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void solve() {
  string s, t; cin>>s>>t;
  vector<int> sc(N, 0), tc(N, 0);
  for (auto c : s) sc[c-'a']++;
  for (auto c : t) tc[c-'a']++;
  for (int i = 0; i < N; i++)
    if (tc[i] < sc[i]) {
      cout<<"Impossible\n";
      return;
    }

  int si = 0;
  for (int i = 0; i < N; i++) tc[i] -= sc[i];
  for (int i = 0; i < N; i++) {
    if (i == s[si]-'a')
      for (; si < s.size() && s[si] <= i+'a'; si++) cout<<s[si];
    for (int j = 0; j < tc[i]; j++) cout<<(char)('a'+i);
  }
  cout<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) solve();
}
