#include <bits/stdc++.h>
#define PI acos(-1)
#define N (1 << 21)
using namespace std;

typedef complex<double> cpx;
typedef vector<cpx> vec;

void fft(vec &f, cpx w) {
  int i, n = f.size();
  if (n == 1) return;

  vec e, o;
  for (i = 0; i < n; i += 2) {
    e.push_back(f[i]);
    o.push_back(f[i+1]);
  }

  fft(e, w*w);
  fft(o, w*w);

  cpx wp(1, 0);
  for (i = 0; i < n/2; i++) {
    f[i] = e[i] + wp * o[i];
    f[i + n/2] = e[i] - wp * o[i];
    wp *= w;
  }
}

int main() {
  int n, i, j, x;
  vec a(N, cpx(0, 0)), c(N);
  vector<bool> p(N, true);
  
  p[0] = p[1] = false;
  for (long long i = 2; i < 1000000; i++) {
    if (!p[i]) continue;

    a[i] = cpx(1, 0);
    for (long long j = i * i; j < 1000000; j+=i) p[j] = false;
  }

  // for (i = 0; i < 500; i++) if (p[i])printf("%d ", i);
  // printf("\n");
  // return 0;

  cpx w(cos(2*PI/N), sin(2*PI/N));
  fft(a, w);
  for (i = 0; i < N; i++) a[i] *= a[i];
  fft(a, cpx(1, 0)/w);

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &x);
		int ans = round(a[x].real());
		int flag = p[x/2];
		if(x/2%2 == 0 && x/2 > 2) flag = 0;
		if(flag) ans--;
		printf("%d\n", ans/2+flag);
  }
}
