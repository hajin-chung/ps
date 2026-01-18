#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void f() {
  int n; cin>>n;
  vector<int> a(n+1); 
  vector<int> p(n+1);
  for (int i = 1; i <= n; i++) {
    cin>>a[i];
    p[a[i]] = i;
  }

  string s; cin>>s;
  if (s[0] == '1' || s[n-1] == '1' || s[p[1]-1] == '1' || s[p[n]-1] == '1') {
    cout<<"-1\n";
    return;
  }

  cout<<"5\n";
  cout<<"1 "<<p[1]<<"\n";
  cout<<"1 "<<p[n]<<"\n";
  cout<<p[1]<<" "<<n<<"\n";
  cout<<p[n]<<" "<<n<<"\n";
  cout<<min(p[1], p[n])<<" "<<max(p[1], p[n])<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
