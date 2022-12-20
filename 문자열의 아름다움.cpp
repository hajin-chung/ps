#include <string>
#include <vector>

using namespace std;

int idx[128];

long long solution(string s) {
    long long answer = 0;
    int len = s.length();
    
    for (int i = 0; i < 128; i++) {
        idx[i] = 300001;
    }
    
    for (int i = 0; i < len; i++) {
        int mx = 300001;
        for(int j = 0; j < 128; j++) {
            if (s[i] != j && idx[j] < mx) mx = idx[j];
        }
        if (mx != 300001) answer += (i - mx);
        if (idx[s[i]] == 300001) idx[s[i]] = i; 
    }
    
    return answer;
}