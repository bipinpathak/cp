#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, i;
    cin >> n;
    vector<int> a(n);
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (i = 1; i < n - 1; i++) {
      if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
        break;
      }
    }
    if (i == n - 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl << i << " " << i + 1 << " " << i + 2 << endl;
    }
  }
  return 0;
}