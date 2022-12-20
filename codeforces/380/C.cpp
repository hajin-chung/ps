#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <deque>
#include <stack>
#define MAX_N 1000000
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void solve() {
  char s[MAX_N+5]; 
  scanf("%s", &s[1]);
  int n = strlen(&s[1]);
   


  int m;
  scanf("%d", &m);
}

int main() {
  solve();
}