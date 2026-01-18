#include <stdio.h>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

priority_queue<int> pq;

int main() {
  int sum = 0;
  int n;

  FILE* f = fopen("1.input.txt", "r");

  while(1) {
    fscanf(f, "%d ", &n);
    if (n == -1) {
      pq.push(sum);
      sum = 0;
    } else if (n == -2) {
      break;
    } else {
      sum += n;
    }

  }
  sum = 0;
  for(int i=0 ; i<3 ; i++) {
    sum += pq.top();
    pq.pop();
  }
  printf("%d", sum);
  return 0;
}