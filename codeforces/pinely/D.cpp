#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <deque>
#include <stack>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

int n, k;

int getK(int i, int idxK) {
  return 
}

void solve() {
  int dp[1000006][2][2];
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}