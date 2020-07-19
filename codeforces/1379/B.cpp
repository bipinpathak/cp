#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long l, r, m, a, b, c, temp;
    cin >> l >> r >> m;
    if (m <= l) {
      a = l;
      b = l;
      c = a + b - m;
    } else {
      a = l;
      while ((m % a > r - l) && (a - (m % a) > r - l)) {
        a++;
      }
      if (m % a <= r - l) {
        c = l;
        b = l + m % a;
      } else {
        b = l;
        c = b + a - m % a;
      }
    }
    cout << a << " " << b << " " << c << endl;
  }
  return 0;
}