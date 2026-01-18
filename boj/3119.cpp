#include <bits/stdc++.h>
using namespace std;

struct Fence {
  int s, e, h, idx;
};
vector<Fence> f;
int n;

bool comp(Fence &a, Fence &b) {
  if (a.s == b.s) {
    if (a.e == b.e) return a.h > b.h;
    return a.e > b.e;
  }
  return a.s < b.s;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); 
  cin>>n; f.resize(n);
  for (int i = 0; i < n; i++) {
    cin>>f[i].s>>f[i].e>>f[i].h;
    f[i].e += f[i].s-1;
    f[i].idx = i+1;
  }
  sort(f.begin(), f.end(), comp); 
  cout<<"\n";
  for (auto [s, e, h, idx] : f) 
    cout << idx << " " << s << " " << e << " " << h << "\n";
  stack<Fence> s;
  vector<int> ans;

  int i = 0;
  while (i < n) {
    if (s.empty()) {
      cout<<"empty: "<<f[i].idx<<"\n";
      s.push(f[i]);
      ans.push_back(f[i++].idx);
      continue;
    }
    cout<<"not empty: "<<f[i].idx<<" "<<s.size()<<"=>";
    while (!s.empty() && s.top().e < f[i].e) s.pop();
    cout<<s.size()<<"\n";
    if (!s.empty()) {
      if (s.top().h < f[i].h) {
        s.push(f[i]);
        ans.push_back(f[i].idx);
      }
      i++;
    }  
  }

  cout<<ans.size()<<"\n";
  sort(ans.begin(), ans.end());
  for (auto ai : ans) cout << ai << " ";
  cout<<"\n";
}
