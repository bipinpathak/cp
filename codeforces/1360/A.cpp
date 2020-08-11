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
    int a, b, side;
    cin >> a >> b;
    if (2 * min(a, b) <= max(a, b)) {
      side = max(a, b);
    } else {
      side = 2*min(a,b);
    }
    cout << side * side << endl;
  }
  return 0;
}