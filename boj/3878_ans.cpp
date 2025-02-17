#include <bits/stdc++.h>


#define for1(s,n) for(int i = s; i<n; i++)

#define for1j(s,n) for(int j = s; j<n; j++)

#define foreach(k) for(auto i : k)

#define foreachj(k) for(auto j : k)

#define pb(a) push_back((a))

#define sz(a) a.size()


using namespace std;

typedef unsigned long long ull;

typedef long long ll;

typedef vector <int> iv1;

typedef vector <vector<int> > iv2;

typedef vector <ll> llv1;

typedef unsigned int uint;

typedef vector <ull> ullv1;

typedef vector <vector <ull> > ullv2;


struct point{

  ll x, y, p=0, q=0;


  bool operator <(point b){

      if(x != b.x) {

          return x < b.x;

      }

      return y < b.y;

  };

  bool operator ==(point b) {

    return y == b.y && x == b.x;

  }

  bool operator <=(point b){

    if(y == b.y && x == b.x) return true;

    if(x != b.x) {

      return x <= b.x;

    }

    return y <= b.y;

  };

};


ll N, M, tc;

vector <point> black;

vector <point> white;


ll ccw(point p1, point p2, point p3) {

  ll ret = 1ll * (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p2.x * p1.y - p3.x * p2.y - p1.x * p3.y);

  return ret > 0 ? 1 : (ret < 0 ? -1 : 0);

}


bool comp(point a, point b) {

  if(a.q * b.p != a.p*b.q) return 1ll * a.q * b.p < a.p * b.q;

  if(a.y != b.y) return a.y < b.y;

  return a.x < b.x;

}


void swapPoint(point a, point b) {

  point tmp;

  tmp = a;

  a = b;

  b= tmp;

}


vector <int> getConvexHull(vector <point>& points) {

  vector <int> stk; stk.clear();


  // y 좌표, x 좌표가 작은 순으로 정렬

  sort(points.begin(), points.end(), comp);


  // 0번째 점을 기준으로 상대 위치 계산

  for(int x=1; x<points.size(); x++) {

      points[x].p = points[x].x - points[0].x;

      points[x].q = points[x].y - points[0].y;

  }


  // 문제 특성상, 두 컨벡스 헐이 겹치는지 판단해야 하므로, 같은 점을 2번 반환한다.

  if(points.size() == 1) {

    return {0, 0};

  }


  // 0번째 점을 제외하고, 반시계 방향으로 정렬(0번째 점을 기준으로 한 상대 위치로 하여금)

  sort(points.begin() + 1, points.end(), comp);


  stk.push_back(0);

  stk.push_back(1);


  for(int next = 2; next < points.size(); next++) {

    // 현재 stack에 쌓인 점이 2개 이상일 때,

    while(stk.size() >= 2) {

      int second = stk.back(); stk.pop_back();

      int first = stk.back();

      

      if(ccw(points[first], points[second], points[next]) > 0) {

        // 이전 점 2개와 비교했을 때, 반시계 방향을 향할 때(좌회전), 다시 second를 넣어준다.

        stk.push_back(second);

        break;

      }

    }

    stk.push_back(next);

  }


  // 컨벡스 헐에 담긴 점들의 idx가 return 된다.

  return stk;

}


bool is_intersected_line(point a, point b, point c, point d) {

  ll line_a_b = ccw(a, b, c) * ccw(a, b, d);

  ll line_c_d = ccw(c, d, a) * ccw(c, d, b);


  if(line_a_b == 0 && line_c_d == 0) {

    if(b < a) swapPoint(a, b);

    if(d < c) swapPoint(c, d);

    return (c <= b && a <= d);

  }

  return line_a_b <= 0 && line_c_d <= 0;

}


void init() {

  ll x, y;


  cin >> N >> M;


  black.clear();

  white.clear();


  for1(0, N) {

    cin >> x >> y;

    black.push_back({ x, y, 0, 0});

  }

  for1(0, M) {

    cin >> x >> y;

    white.push_back({x, y, 0, 0});

  }

}


int main() {

  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


  cin >> tc;


  while(tc--) {

    init();


    if(N==1 && M ==1) {

      /* 각각 점이 한 개씩 있는 경우, 두 그룹으로 나눌 수 있다. */

      cout <<"YES\n";

      continue;

    }


    vector <int> black_covex_hull = getConvexHull(black);

    vector <int> white_convex_hull = getConvexHull(white);

    

    bool invalid = false;

    int black_size = black_covex_hull.size();

    int white_size = white_convex_hull.size();


    // convex hull의 각 선분별로 서로 겹치는지 검사한다.

    for1(0, black_size) {

      for1j(0, white_size) {

        point a,b,c,d;

        a = black[black_covex_hull[i]];

        b = black[black_covex_hull[(i+1) % black_size]];

        c = white[white_convex_hull[j]];

        d = white[white_convex_hull[(j+1) % white_size]];

        if(is_intersected_line(a, b, c, d)) {

          invalid = true;

          break;

        }

      }

      if(invalid) break; 

    }


    /* 아래 경우는 교차하지 않는 두 컨벡스 헐임을 고려해야 한다. */


    bool black_convex_hull_include_white_point = true;

    bool white_convex_hull_include_black_point = true;


    // white 점이 black convex hull 안에 포함되어 있는지 검사한다.

    for1(0, black_size) {

      for1j(0, white_size) {

        point a, b, c;

        a = black[black_covex_hull[i]];

        b = black[black_covex_hull[(i+1) % black_size]];

        c = white[white_convex_hull[j]];

        

        // 하나의 하얀색 점이아도 시계 방향을 향하는 점이라면,

        // white convex hull이 black convex hull에 포함되지 않는다.

        if(ccw(a, b, c) <= 0) {

          black_convex_hull_include_white_point = false;

          break;

        }

      }

      if(!black_convex_hull_include_white_point) break;

    }

    

    if(black_convex_hull_include_white_point) invalid = true;


    // black 점이 white convex hull 안에 포함되어 있는지 검사한다.

    for1(0, white_size) {

      for1j(0, black_size) {

        point a, b, c;

        a = white[white_convex_hull[i]];

        b = white[white_convex_hull[(i+1) % white_size]];

        c = black[black_covex_hull[j]];


        // 하나의 검은색 점이아도 시계 방향을 향하는 점이라면,

        // black convex hull이 white convex hull에 포함되지 않는다.

        if(ccw(a, b, c) <= 0) {

          white_convex_hull_include_black_point = false;

          break;

        }

      }

      if(!white_convex_hull_include_black_point) break;

    }


    if(white_convex_hull_include_black_point) invalid = true;


    cout << (invalid ? "NO" : "YES") << "\n";

  }

}
