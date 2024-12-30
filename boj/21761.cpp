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
    int idx = 0; ll mn = 0;
    for (int i = 0; i < 4; i++)
      if (!card[i].empty()) {
        ll mult = a[i] + card[i].back();
        for (int j = 0; j < 4; j++)
          if (i != j)
            mult *= a[j];
        if (mult > mn) {
          mn = mult; idx = i;
        }
      }
    a[idx] += card[idx].back();
    ans.push_back({idx+'A', card[idx].back()});
    card[idx].pop_back();
  }
  for (auto [c, x] : ans) cout<<c<<" "<<x<<"\n";
}
