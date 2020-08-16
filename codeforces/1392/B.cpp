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
    int n, i, low = 1e9, high = -1 * 1e9;
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    for (i = 0; i < n; i++) {
      cin >> a[i];
      low = min(low, a[i]);
      high = max(high, a[i]);
    }
    if (k % 2) {
      for (i = 0; i < n; i++) {
        a[i] = high - a[i];
      }
    } else {
      for (i = 0; i < n; i++) {
        a[i] -= low;
      }
    }
    for (i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
  return 0;
}