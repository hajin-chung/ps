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
    cout << "hihi" << endl;
    if (!flag) {
      cout << "hihi2" << endl;
      Trie next = new Trie(s[i], i == s.size()-1);
      curr->children.push_back(&next);
      curr = &next;
    }
  }
}

int walk(Trie* curr, int lev) {
  if (curr->children.size() <= 1) return lev;
  else {
    int sum = 0;
    if (curr->isWord) sum += lev;
    for (auto next : curr->children) 
      sum += walk(next, lev+1);
    return sum;
  } 
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
      cout << s << endl;
      add(root, s);
    }
    cout << walk(root, 0) << endl;
  }
}
