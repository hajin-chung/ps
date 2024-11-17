#include <bits/stdc++.h>
#define N 500000
#define FASTIO ios::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;

const double PI = acos(-1);
typedef complex<double> cpx;
typedef long long ll;
const int SZ = 1<<20;
int n;

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

vector<ll> mul(vector<ll> &a) {
	vector<ll> ret(n);
	vector<cpx> f(all(a));
	f.resize(SZ); fft(f,0);
	for(int i=0;i<f.size();i++) f[i]*=f[i];
	fft(f,1);
	for(int i=1;i<f.size();i++) ret[i%n] += (ll)round(f[i].real());
	return ret;
}

int main() {
	FASTIO;
	cin>>n;
	vector<ll> a(n), sq(n);
	for (ll i = 1; i < n; i++) {
		a[(i*i)%n]++;
		sq[2*i*i%n]++;
	}
	auto ret = mul(a);
	ll ans = 0;
	for (ll i = 1; i < n; i++) {
		ll k = i*i%n;
		ll a = ret[i*i%n];
		ll eq = sq[k];
		ans += (a-eq)/2+eq;
	}
	cout<<ans<<"\n";
}
