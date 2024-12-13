#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int n, cnt[1005];

void print(int i, int c) { 
  while (c--) cout<<i<<" ";
  cout<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int x; cin>>n;
  for (int i = 0; i < n; i++) {
    cin>>x;
    cnt[x]++;
  }
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  for (int i = 0; i <= 1000; i++) 
    if (cnt[i])
      pq.push({i, cnt[i]});

  vector<pii> ans;
  auto [f, fc] = pq.top(); pq.pop();
  ans.push_back({f, fc});
  while (!pq.empty()) {
    int f = ans.back().first;
    auto [s, sc] = pq.top(); pq.pop();
    if (f+1 == s) {
      if (pq.empty()) {
        auto [f, fc] = ans.back(); ans.pop_back();
        ans.push_back({s, sc});
        ans.push_back({f, fc});
        continue;
      } else {
        auto [t, tc] = pq.top(); pq.pop();
        ans.push_back({t, tc});
      }
    }
    ans.push_back({s, sc});
  }
  for (auto [i, c] : ans) 
    while(c--)
      cout<<i<<" ";
  cout<<"\n";
}
