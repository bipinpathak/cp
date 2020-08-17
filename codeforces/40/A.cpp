#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int x, y, d;
  string ans = "black";
  cin >> x >> y;
  d = sqrt(x * x + y * y);
  if (d * d != x * x + y * y) {
    if (d % 2) {
      if ((x > 0 && y > 0) || (x < 0 && y < 0)) {
        ans = "white";
      }
    } else {
      if ((x < 0 && y > 0) || (x > 0 && y < 0)) {
        ans = "white";
      }
    }
  }
  cout << ans << endl;
  return 0;
}