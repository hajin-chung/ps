#include <bits/stdc++.h>
using namespace std;

struct Trie {
  bool term;
  typedef pair<int, Trie*> pit;
  map<char, pit> c;
  Trie() : term(false) {}
};

int n, ans;
vector<pair<int, string>> a;
vector<char> ops;

void insert(Trie* root, string &s) {
  Trie *curr = root;
  for (auto c : s) {
    if (!curr->c.count(c)) curr->c[c] = {s.size(), new Trie()};
    if (curr->c[c].first < s.size()) curr->c[c].first = s.size();
    curr = curr->c[c].second;
  }
  curr->term = true;
}

void traverse(Trie* curr) {
  if (curr->term) {
    ops.push_back('P');
    return;
  }
  vector<pair<int, pair<char, Trie*>>> v;
  for (auto [c, iT] : curr->c) v.push_back({iT.first, {c, iT.second}});
  sort(v.begin(), v.end());
  for (auto [l, cT] : v) {
    auto [c, next] = cT;
    ops.push_back(c);
    traverse(next);
    ops.push_back('-');
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  a.resize(n);
  Trie *trie = new Trie();
  for (auto &[l, s] : a) {
    cin >> s;
    l = s.size();
    insert(trie, s);
  }

  traverse(trie);
  while (ops.back() == '-') ops.pop_back();
  cout << ops.size() << "\n";
  for (auto c : ops) cout << c << "\n";
}
