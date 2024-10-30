#include <bits/stdc++.h>
using namespace std;

struct Trie {
  bool term;
  int ml;
  map<char, Trie*> c;
  Trie() : term(false) {}
};

int n, ans;
vector<pair<int, string>> a;
vector<char> ops;

void insert(Trie* root, string &s) {
  Trie *curr = root;
  for (auto c : s) {
    if (!curr->c.count(c)) curr->c[c] = new Trie();
    if (curr->c[c]->ml < s.size()) curr->c[c]->ml = s.size();
    curr = curr->c[c];
  }
  curr->term = true;
}

void traverse(Trie* curr) {
  if (curr->term) {
    ops.push_back('P');
    return;
  }
  vector<pair<int, char>> v;
  for (auto [c, next] : curr->c) v.push_back({next->ml, c});
  sort(v.begin(), v.end());
  for (auto [ml, c] : v) {
    ops.push_back(c);
    traverse(curr->c[c]);
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
