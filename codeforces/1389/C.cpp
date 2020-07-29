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
    string s;
    cin >> s;
    int a, b, ans = 0, n = s.length();
    for (a = 0; a <= 9; a++) {
      for (b = 0; b <= 9; b++) {
        int ca = 0, cb = 0;
        for (char c : s) {
          if ((c == '0'+a) && (ca <= cb)) {
            ca++;
          } else if((c=='0'+b) && cb<ca) {
            cb++;
          }
        }
        if(a==b) {
          ans = max(ans, ca+cb);
        } else {
          ans = max(ans, 2 * min(ca, cb));
        }
      }
    }
    cout << n - ans << endl;
  }
  return 0;
}