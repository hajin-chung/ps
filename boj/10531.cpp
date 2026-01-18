#include <bits/stdc++.h>
#define PI acos(-1)
#define N 1 << 21
using namespace std;

typedef complex<double> cpx;
typedef vector<cpx> vec;

bool d[N];

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

int mul(vector<int> A) {
  int n = N, cnt = 0, i;
  vec a, c;

  a.resize(n);
  c.resize(n);
  a[0] = 1;
  for (auto i : A) a[i] = cpx(1, 0);
  cpx w(cos(2*PI/n), sin(2*PI/n));
  fft(a, w);
  for (i = 0; i < n; i++) c[i] = a[i] * a[i];

  fft(c, cpx(1, 0)/w);
  for (i = 0; i < n; i++) {
    int x = round(c[i].real() / n);
    if (x > 0 && d[i]) cnt++;
  }

  return cnt;
}

int main() {
  int n, m, i, x;
  vector<int> b, a;

  scanf("%d", &n);
  a.resize(n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);

  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    scanf("%d", &x);
    d[x] = true;
  }

  int ans = mul(a);
  printf("%d", ans);
}

