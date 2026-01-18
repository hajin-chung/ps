#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define PI acos(-1)
#define N (1 << 21)
using namespace std;

typedef long long int ll;
typedef complex<double> cpx;
typedef vector<cpx> poly;
const double pi = acos(-1);

void fft(poly &f, bool inv = 0){
  int n = f.size(), j = 0;
  vector<cpx> root(n >> 1);
  for(int i=1; i<n; i++){
    int bit = (n >> 1);
    while(j >= bit) j -= bit, bit >>= 1;
    j += bit;
    if(i < j) swap(f[i], f[j]);
  }
  double ang = 2 * pi / n; if(inv) ang *= -1;
  for(int i=0; i<n/2; i++) root[i] = cpx(cos(ang*i), sin(ang*i));
  for(int i=2; i<=n; i<<=1){
    int step = n / i;
    for(int j=0; j<n; j+=i)
      for(int k=0; k<i/2; k++){
	cpx u = f[j | k], v = f[j | k | i/2] * root[step * k];
	f[j | k] = u + v; 
	f[j | k | i/2] = u - v;
      }
  }
  if(inv) for(int i=0; i<n; i++) f[i] /= n;
}
vector<ll> multiply(const vector<ll> &_a, const vector<ll> &_b){
  poly a(all(_a)), b(all(_b));
  int n = 1; while(n < a.size() + b.size()) n <<= 1;
  a.resize(n); b.resize(n);
  fft(a); fft(b);
  for(int i=0; i<n; i++) a[i] *= b[i];
  fft(a, 1);
  vector<ll> ret(n); 
  for(int i=0; i<n; i++) ret[i] = round(a[i].real());
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  vector<ll> a(1000000, 1);
  for (int i = 2; i < 1000; i++) if (a[i]) {
      for (int j = i * i; j < 1000000; j += i) a[j] = 0;
  }
  vector<ll> b(500000), c;
  for (int i = 3; i < 1000000; i += 2) if (a[i]) b[i / 2] = 1;
  c = b;
  vector<ll> ans = multiply(b, c);
  int n;
  cin >> n;
  while (n--) {
    int x; cin >> x;
    cout << ans[x / 2 - 1] / 2 + a[x / 2] << '\n';
  }
}
