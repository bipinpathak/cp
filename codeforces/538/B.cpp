#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  vector<int> ans;
  cin >> n;
  while (n) {
    int build=0;
    string s = to_string(n);
    for (char c : s) {
      build *= 10;
      if (c != '0') {
        build++;
      }
    }
    ans.push_back(build);
    n -= build;
  }
  cout << ans.size() << endl;
  for (int i : ans) {
    cout << i << " ";
  }
  return 0;
}