#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

vector<int> solve(int N, int k) {
  ordered_set s;
  for(int i = 1; i <= N; ++i) s.insert(i);
  vector<int> elimination_order;
  int idx = 0;
  while(!s.empty()) {
    idx = (idx + k - 1) % s.size();
    auto it = s.find_by_order(idx);
    elimination_order.push_back(*it);
    s.erase(it);
  }
  return elimination_order;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  auto ans = solve(n, k);
  printf("<");
  for (int i = 0; i < n; i++) {
    printf("%d", ans[i]);
    if (i != n-1) printf(", ");
    else printf(">\n");
  }
}
