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
    int r, g, b, w, m, odd = 0;
    string ans = "No";
    cin >> r >> g >> b >> w;
    m = min(r, min(g, b));
    if (r % 2) {
      odd++;
    }
    if (g % 2) {
      odd++;
    }
    if (b % 2) {
      odd++;
    }
    if (odd == 0) {
      ans = "Yes";
    } else if (odd == 1  && w%2==0)  {
      ans = "Yes";
    } else if (odd == 2 && w % 2 == 1 && m>0) {
      ans = "Yes";
    } else if (odd == 3) {
      ans = "Yes";
    }
    cout << ans << endl;
  }
  return 0;
}