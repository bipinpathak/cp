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
    int x1, y1, z1, x2, y2, z2, ans = 0, temp;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    temp=min(z1, y2);
    ans += 2 * temp;
    z1 -= temp;
    y2 -= temp;
    if(z1) {
      temp = min(z1, z2);
      z1 -= temp;
      z2 -= temp;
    }
    if(z2>x1) {
      ans -= 2 * (z2 - x1);
    }
    cout << ans << endl;
  }
  return 0;
}