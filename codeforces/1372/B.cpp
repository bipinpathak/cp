#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n, i = 2, temp;
    cin >> n;
    temp = n / i;
    while (i <= sqrt(n) && n % temp != 0) {
      if (i == 2) {
        i--;
      }
      i += 2;
      temp = n / i;
    }
    if (i > sqrt(n)) {
      temp = 1;
    }
    cout << temp << " " << n - temp << endl;
  }
  return 0;
}