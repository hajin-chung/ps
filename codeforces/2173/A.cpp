#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void solve() {
  int n, k; cin>>n>>k;
  int cd = 0, cnt = 0;
  while (n--) {
    char b; cin>>b;
    if (b == '1') cd = k;
    else {
      if (cd == 0) cnt++;
      else cd--;
    }
  }
  cout<<cnt<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) solve();
}
