#include <bits/stdc++.h>
#define LOG_MAX 30
using namespace std;

struct Trie {
  Trie *z;
  Trie *o;
  Trie() : z(nullptr), o(nullptr) {}
};
int n;
vector<int> a;

void insert(Trie* root, int num) {
  Trie *curr = root;
  for (int i = (int)30; i >= 0; i--) {
    if (num & (1 << i)) {
      if (curr->o == nullptr) curr->o = new Trie();
      curr = curr->o;
    }
    else {
      if (curr->z == nullptr) curr->z = new Trie();
      curr = curr->z;
    }
    num = num & (~(1<<i));
  }
}

int find(Trie* root, int num) {
  Trie *curr = root;
  int ret = 0;
  for (int i = LOG_MAX; i >= 0; i--) {
    if (num & (1 << i)) {
      if (curr->z != nullptr) {
        curr = curr->z;
        ret += (1<<i);
      } else if (curr->o != nullptr) {
        curr = curr->o;
      } else {
        break;
      }
    } else {
      if (curr->o != nullptr) {
        curr = curr->o;
        ret += (1<<i);
      } else if (curr->z != nullptr) {
        curr = curr->z;
      } else {
        break;
      }
    }
  }
  return ret;
}

int main() {
  Trie* root = new Trie();
  scanf("%d", &n); 
  int x;
  for (int i = 0; i < n; i++) {
    scanf("%u", &x);
    a.push_back(x);
    insert(root, x);
  }

  int ans = 0;
  for (int i = 0; i < n; i++)
    ans = max(ans, find(root, a[i]));
  printf("%u\n", ans);
}
