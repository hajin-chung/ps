#include <bits/stdc++.h>
using namespace std;

char s[1000005], p[1000005];
int ds[1000005], dp[1000005];
vector<int> ans;

int getline(char* c) {
  char x;
  int idx = 0;
  while (x = getchar()) {
    if (x == '\n') break;
    else c[idx++] = x;
  }
  return idx;
}

int main() {
  int i, j, sn, pn;

  sn = getline(s);
  pn = getline(p);

  if (pn > sn) {
    printf("0\n");
    return 0;
  }

  i = 1; j = 0;
  while (i < pn) {
    if (p[i] == p[j]) {
      dp[i] = j+1;
      j++;
      i++;
    } else if (j > 0) {
      j = dp[j-1];
    } else {
      dp[j] = 0;
      i++;
    }
  }

  i = j = 0;
  while (i < sn) {
    if (s[i] == p[j]) {
      if (j == pn-1) {
        ans.push_back(i-j);
        j = dp[j]; 
        i++;
      } else {
        i++;
        j++;
      }
    } else {
      if (j > 0) j = dp[j-1];
      else i++;
    }
  }

  printf("%d\n", ans.size());
  for (auto idx : ans) printf("%d ", idx+1);
  printf("\n");
}
