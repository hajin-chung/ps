#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;

int dp[2505], isPalindrome[2502][2502];
char a[2505];

int main() {
  scanf("%s", &a[1]);
  int n = strlen(&a[1]);

  for (int l = 0; l < n; l++)
    for (int st = 1; st <= n-l; st++) {
      if (l == 0) isPalindrome[st][st+l] = true;
      else if (l == 1) isPalindrome[st][st+l] = a[st] == a[st+l];
      else isPalindrome[st][st+l] = ((a[st] == a[st+l]) && isPalindrome[st+1][st+l-1]);
    }

  for (int i = 1; i <= n; i++) {
    dp[i] = i;
    for (int j = 1; j <= i; j++) {
      if (isPalindrome[j][i])
        dp[i] = min(dp[i], dp[j-1]+1);
    }
  }

  printf("%d\n", dp[n]);
}
