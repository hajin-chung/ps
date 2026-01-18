#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> v[10];
vector<char> ss;

int main()
{
  FILE* f = fopen("5.input.txt", "r");

  int n, m;
  char x;
  fscanf(f, "%d", &n);
  for(int i=1; i<=n; i++) {
    fscanf(f, " %d", &m);
    for(int j=0; j<m; j++) {
      fscanf(f, " %c", &x);
      v[i].push_back(x);
    }
  }

  fscanf(f, " %d ", &m);
  for(int i=0; i<m; i++) {
    int mv, s, e;

    fscanf(f, "move %d from %d to %d\n", &mv, &s, &e);
    printf("%d %d %d\n", mv, s, e);
    for(int j=0; j<mv; j++) {
      char b = v[s].back();
      v[s].pop_back();
      ss.push_back(b);
    }
    for(int j=0; j<mv; j++) {
      char b = ss.back();
      ss.pop_back();
      v[e].push_back(b);
    }
  }


  for(int i=1; i<10; i++) {
    printf("%c", v[i].back());
  }
}
