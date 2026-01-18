#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
ll cnt[26];
int lookup[26], n;
vector<string> a;

ll tpow(int n) {
  ll ret = 1;
  while (n--) ret *= 10;
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);  
  for (int i = 0; i < 26; i++) lookup[i] = -1;
  cin>>n;
  for (int i = 0; i < n; i++) {
    string s;
    cin>>s;
    a.push_back(s);
    for (int j = 0; j < s.size(); j++)
      cnt[s[j]-'A'] += tpow(s.size()-j-1);
  }

  vector<pair<ll, int>> cni;
  for (int i = 0; i < 26; i++)
    if (cnt[i] > 0)
      cni.push_back({cnt[i], i});
  sort(cni.begin(), cni.end());
  int num = 9;
  ll ans = 0;
  for (int i = cni.size()-1; i >= 0; i--) {
    ans += cni[i].first * num;
    num--;
  }
  cout<<ans<<"\n";
}
