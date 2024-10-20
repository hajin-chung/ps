#include <string>
#include <vector>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
  vector<double> answer;
  vector<int> heights;
  vector<double> psum;
  int n = 0;
  heights.push_back(k);
  while (k != 1) {
    if (k % 2 == 0) k /= 2;   
    else k = k*3 + 1;
    n++;
    heights.push_back(k);
  }
  psum.resize(n+1);
  for (int i = 1; i <= n; i++) 
    psum[i] = psum[i-1] + ((double)heights[i]+heights[i-1])/2;
  for (auto range : ranges) {
    if (range[0] == 0) answer.push_back(psum[n-range[1]]);
    else answer.push_back(psum[n-range[1]] - psum[range[0]]);
  }
  return answer;
}
