#include <bits/stdc++.h>
using namespace std;

struct T {
  bool t;
  T *ch[2];
};
typedef pair<int, int> pii;
vector<string> ans;

bool query(T *curr, int lev, int target, int idx, string &s) {
  if (lev > target) return false;
  if (curr->t) return false;
  if (lev == target && !curr->t) {
    curr->t = 1;
    ans[idx] = s;
    return true;
  }
  if (!curr->ch[0]) curr->ch[0] = new T;
  if (!curr->ch[1]) curr->ch[1] = new T;
  s.push_back('0');
  bool ret = query(curr->ch[0], lev+1, target, idx, s);
  s.pop_back();
  if (ret) return ret;
  s.push_back('1');
  ret = query(curr->ch[1], lev+1, target, idx, s);
  s.pop_back();
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<pii> a(n);
  for (int i = 0; i < n; i++) {
    int x; cin>>x;
    a[i] = {x, i};
  }
  sort(a.begin(), a.end());
  ans.resize(n);
  T* trie = new T;
  for (auto [x, i] : a) {
    string s = "";
    if (!query(trie, 0, x, i, s)) {
      cout<<"-1\n";
      return 0;
    }
  }
  cout<<"1\n";
  for (auto s : ans) cout<<s<<"\n";
}
