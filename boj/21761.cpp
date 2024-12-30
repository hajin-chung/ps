#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k; cin>>n>>k;
  ll a[4];
  vector<ll> card[4]; 
  for (int i = 0; i < 4; i++) cin>>a[i];
  for (int i = 0; i < n; i++) {
    char c; ll x; cin>>c>>x;
    card[c-'A'].push_back(x);
  }
  for (int i = 0; i < 4; i++)
    if (!card[i].empty())
      sort(card[i].begin(), card[i].end());
  vector<pair<char, ll>> ans;
  while (k--) {
    int idx = 0, ucnt = 0;
    vector<int> cnt(4);
    for (int i = 0; i < 4; i++) 
      if (!card[i].empty()) {
        ucnt++;
        cnt[i] = 1;
      }
    for (int i = 0; i < 4; i++)
      for (int j = i+1; j < 4; j++) 
        if (!card[i].empty() && !card[j].empty()) {
          ll ai = card[i].back()*a[j], aj = card[j].back()*a[i];
          if (ai > aj) cnt[i]++;
          else cnt[j]++;
        }
    for (int i = 0; i < 4; i++) if (ucnt == cnt[i]) idx = i;
    a[idx] += card[idx].back();
    ans.push_back({idx+'A', card[idx].back()});
    card[idx].pop_back();
  }
  for (auto [c, x] : ans) cout<<c<<" "<<x<<"\n";
}
