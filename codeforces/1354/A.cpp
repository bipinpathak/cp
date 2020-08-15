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
    long long a, b, c, d, ans=-1;
    cin >> a >> b >> c >> d;
    a -= b;
    if (a <= 0) {
      ans = b;
    } else if (c > d) {
      ans = b + c * ((a + c - d - 1) / (c - d));
    }
    cout << ans << endl;
  }
  return 0;
}