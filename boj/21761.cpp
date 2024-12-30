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
    sort(card[i].begin(), card[i].end());
  vector<pair<char, ll>> ans;
  while (k--) {
    int idx = 0;
    vector<int> cnt(4);
    for (int i = 0; i < 4; i++)
      for (int j = i+1; j < 4; j++) 
        if (!card[i].empty() && !card[j].empty()) {
          ll ai = card[i].back()*a[j], aj = card[j].back()*a[i];
          if (ai > aj) cnt[i]++;
          else if (ai < aj)cnt[j]++;
        }
    for (int i = 0; i < 4; i++) cout<<cnt[i]<<" ";
    cout<<"\n";
    for (int i = 0; i < 4; i++) if (cnt[i] > cnt[idx]) idx = i;
    a[idx] += card[idx].back();
    ans.push_back({idx+'A', card[idx].back()});
    card[idx].pop_back();
  }
  for (auto [c, x] : ans) cout<<c<<" "<<x<<"\n";
}
