#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
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
