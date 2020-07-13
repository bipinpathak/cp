#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, i, rc = 0, pc = 0, sc = 0;
    string s, ans, rock, paper, scissors;
    cin >> s;
    n = s.length();
    for (i = 0; i < n; i++) {
      if (s[i] == 'R') {
        rc++;
      } else if (s[i] == 'P') {
        pc++;
      } else {
        sc++;
      }
      rock += 'R';
      paper += 'P';
      scissors += 'S';
    }
    if (rc >= pc && rc >= sc) {
      ans = paper;
    } else if (pc >= rc && pc >= sc) {
      ans = scissors;
    } else {
      ans = rock;
    }
    cout << ans << endl;
  }
  return 0;
}