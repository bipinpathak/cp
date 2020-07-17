#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int x, y, z, a, b, c;
    cin >> x >> y >> z;
    if ((x == y && x == max(x, max(y, z))) ||
        (y == z && y == max(x, max(y, z))) ||
        (x == z && z == max(x, max(y, z)))) {
      cout << "YES" << endl;
      cout << max(x, max(y, z)) << " " << min(x, min(y, z)) << " "
           << min(x, min(y, z)) << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}