#include <bits/stdc++.h>
using namespace std;

struct Trie {
  bool erase, save, eraseEnd;
  Trie *next[256];

  Trie(): erase(false), save(false), eraseEnd(false) {}
};

void insert(Trie* root, string s, bool erase) {
  Trie *node = root;
  for (auto _c : s) {
    int c = (int)_c;
    if (!node->next[c]) node->next[c] = new Trie();
    if (erase) node->next[c]->save = true;
    else node->next[c]->erase = true;
    node = node->next[c];
  }
  if (!erase) node->eraseEnd = true;
}

int rec(Trie* node) {
  bool flag = true;
  int ret = 0;
  for (int i = 0; i < 256; i++) {
    if (node->next[i]->erase) {
      if
    }
  }
}

void solve() {
  int n;
  string s;
  cin>>n;
  Trie *root = new Trie();
  while (n--) {
    cin>>s;
    insert(root, s, false);
  }
  cin>>n;
  while (n--) {
    cin>>s;
    insert(root, s, true);
  }
  cout << rec(root) << "\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); 
  int t; cin>>t;
  while(t--) solve();
}
