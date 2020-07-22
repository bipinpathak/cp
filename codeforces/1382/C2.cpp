#include <bits/stdc++.h>
using namespace std;
void build(string s, vector<int>& ans) {
  int n = s.length(), i;
  for (i = 0; i < n - 1; i++) {
    if (s[i] != s[i + 1]) {
      ans.push_back(i + 1);
    }
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string a, b;
    cin >> n >> a >> b;
    vector<int> first, second;
    build(a, first);
    build(b, second);
    if(a[n-1]!=b[n-1]) {
      first.push_back(n);
    }
    cout << first.size() + second.size();
    for (int i = 0; i < first.size(); i++) {
      cout << " " << first[i];
    }
    for (int i = second.size()-1; i >=0; i--) {
      cout << " " <<second[i];
    }
    cout << endl;
  }
  return 0;
}