#include <bits/stdc++.h>
#define MAX 1000000000
using namespace std;

typedef long long int ll;
typedef pair<ll, string> term;
typedef pair<string, vector<term>> equation;
vector<equation> equations;
map<string, ll> d;
int n, m;

ll convert(ll s) {
  return s > MAX ? MAX+1 : s;
}

ll calculate(vector<term> terms) {
  ll sum = 0;
  for (auto [n, x] : terms) {
    if (d.count(x) > 0) sum = convert(sum + n * d[x]);
    else return -1;
  }
  return sum;
}

int main() {
  char tmp[100];
  scanf("%d%d", &n, &m); 
  for (int i = 0; i < n; i++) {
    ll w;
    memset(tmp, 0, sizeof(tmp));
    scanf("%s %lld", tmp, &w);
    string str = tmp;
    d[str] = w;
  }

  for (int i = 0; i < m; i++) {
    scanf("%s", tmp);
    string lhs = "";
    vector<term> terms;
    int len = strlen(tmp);
    int j = 0;
    for (; j < len; j++) {
      if (tmp[j] == '=') {
        j++;
        break;
      } else {
        lhs += tmp[j];
      }
    }
    while (j < len) {
      int n = tmp[j] - '0'; j++;
      string x = "";
      while (tmp[j] != '+' && j < len) {
        x += tmp[j];
        j++;
      }
      j++;
      terms.push_back({n, x});
    }
    equations.push_back({lhs, terms});
  }

  bool flag = true;
  while (flag) {
    flag = false;
    for (auto [lhs, terms] : equations) {
      ll sum = calculate(terms);
      if (sum == -1) continue;
      if (d.count(lhs) == 0 || d[lhs] > sum) {
        flag = true;
        d[lhs] = convert(sum);
      }
    }
  }

  if (d.count("LOVE") == 0) printf("-1\n");
  else printf("%lld\n", d["LOVE"]);
}
