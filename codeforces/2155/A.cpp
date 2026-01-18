#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

const int N = 500;
int dp[N+1][N+1];

void pre() {
  dp[1][1] = 1;
  for (int i = 1; i <= N; i++)
    for (int j = 0; j <= N; j++)
      if (i != 1 || (i == 1 && j >= 2))
        dp[i][j] = i/2 + j/2 + dp[i-i/2][j-j/2+i/2];
}

void f() {
  int n; cin>>n;
  cout<<dp[n][0]<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  pre();
  int t; cin>>t;
  while(t--) f();
}
