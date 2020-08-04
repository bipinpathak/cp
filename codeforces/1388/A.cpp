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
    int n;
    cin >> n;
    if (n <= 30) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      int a = 6, b = 10, c = 14;
      if (n == 36 || n == 40 || n == 44) {
        c = 15;
      }
      n -= a + b + c;
      cout << a << " " << b << " " << c << " " << n << endl;
    }
  }
  return 0;
}