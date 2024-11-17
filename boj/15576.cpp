#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define N 300000
using namespace std;

const double PI = acos(-1);
typedef complex<double> cpx;
typedef long long ll;
const int SZ = 1<<20;

void fft(vector<cpx> &f, bool is_rev) {
	int n = (int)f.size();
	for(int i=1,j=0;i<n;i++) {
		int b=(n>>1);
		while(!((j^=b)&b)) b>>=1;
		if(i<j) swap(f[i],f[j]);
	}

	for(int s=1;s<n;s<<=1) {
		double t = PI/s * (is_rev?1:-1);
		cpx w(cos(t),sin(t));
		for(int i=0;i<n;i+=(s<<1)) {
			cpx wp(1,0);
			for(int j=0;j<s;j++) {
				cpx tp = f[s|i|j] * wp;
				f[s|i|j]=f[i|j]-tp;
				f[i|j]+=tp;
				wp *= w;
			}
		}
	}
	if(is_rev) for(int i=0;i<n;i++) f[i]/=n;
}

void mul(vector<cpx> &a, vector<cpx> &b) {
	a.resize(SZ); fft(a,0);
	b.resize(SZ); fft(b,0);
	for(int i=0;i<a.size();i++) a[i]*=b[i];
	fft(a,1);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  vector<cpx> a(N, cpx(0, 0)), b(N, cpx(0, 0));
  string sa, sb;
  cin>>sa>>sb;
  int na = sa.size(), nb = sb.size();
  for (int i = 0; i < na; i++)
    a[i] = cpx(sa[i]-'0', 0);
  for (int i = 0; i < nb; i++)
    b[i] = cpx(sb[i]-'0', 0);
  mul(a, b);
  string ans = "";
  int carry = 0;
  while (round(a.back().real()) != 0) a.pop_back();
  for (int i = 0; i < a.size(); i++) {
    int digit = (int)round(a[i].real());
    carry += digit;
    ans.push_back(carry%10 + '0');
    carry /= 10;
  }
  while (ans.back() == '0') ans.pop_back();
  reverse(all(ans));
  cout<<ans<<"\n";
}
