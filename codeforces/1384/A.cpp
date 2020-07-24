#include <bits/stdc++.h>
using namespace std;
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
    int n, i, m = 0;
    cin >> n;
    vector<int> a(n);
    for (i = 0; i < n; i++) {
      cin >> a[i];
      m = max(m, a[i]);
    }
    string s, temp;
    i = 0;
    while (i < m) {
      s += 'a';
      i++;
    }
    if (m == 0) {
      for (i = 0; i < n + 1; i++) {
        if (i % 2) {
          cout << "a" << endl;
        } else {
          cout << "b" << endl;
        }
      }
    } else {
      cout << s << endl;
      for (i = 0; i < n; i++) {
        if (a[i]) {
          temp = s.substr(0, min((int)s.length(), a[i]));
        } else {
          temp = "";
        }
        while (temp.length() < a[i]) {
          temp += s[temp.length()];
        }
        while (temp.length() < m) {
          temp += s[temp.length()] == 'a' ? 'b' : 'a';
        }
        cout << temp << endl;
        s = temp;
      }
    }
  }
  return 0;
}