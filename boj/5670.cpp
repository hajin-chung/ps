#include <bits/stdc++.h>
using namespace std;

struct Trie {
  char c;
  bool isWord;
  vector<Trie*> children;

  Trie(bool iw): isWord(iw), children(vector<Trie*>()) {}
  Trie(char C, bool iw) : c(C), isWord(iw), children(vector<Trie*>()) {}
};

void add(Trie* root, string s) {
  Trie* curr = root;
  for (int i = 0; i < s.size(); i++) {
    bool flag = false;
    for (auto next : curr->children)
      if (next->c == s[i]) {
        flag = true;
        curr = next;
        break;
      }
    if (!flag) {
      Trie *next = new Trie(s[i], i == s.size()-1);
      curr->children.push_back(next);
      curr = next;
    }
    if (i == s.size()-1) curr->isWord = true;
  }
}

int walk(Trie* curr, int lev) {
  // cout << curr->c << " " << lev << " " << (curr->isWord ? "word" : "no") << endl;
  int ret = 0;
  if (curr->isWord) ret = lev;
  if (curr->children.size() == 1) ret += walk(curr->children[0], lev + curr->isWord);
  else for (auto next : curr->children) ret += walk(next, lev+1);
  // cout << curr->c << " " << lev << " " << curr->isWord ? "word" : "no";
  // cout << " " << ret << endl;
  return ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  while (cin >> n) {
    Trie* root = new Trie(false);
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      add(root, s);
    }
    int sum = 0;
    for (auto next : root->children) sum += walk(next, 1);
    cout << fixed;
    cout.precision(2);
    cout << (double)sum/n << endl;
  }
}
