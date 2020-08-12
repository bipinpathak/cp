#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  stack<char> a;
  for (char c : s) {
    if (a.size() && a.top() == c) {
      a.pop();
    } else {
      a.push(c);
    }
  }
  if (a.size() == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}