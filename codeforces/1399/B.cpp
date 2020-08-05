#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, i;
    cin >> n;
    long long ans = 0, candy = INT_MAX, orange = INT_MAX;
    vector<long long> a(n), b(n);
    for (i = 0; i < n; i++) {
      cin >> a[i];
      candy = min(candy, a[i]);
    }
    for (i = 0; i < n; i++) {
      cin >> b[i];
      orange = min(orange, b[i]);
    }
    for (i = 0; i < n; i++) {
      a[i] -= candy;
      b[i] -= orange;
      long long steps = 0;
      steps = min(a[i], b[i]);
      a[i] -= steps;
      b[i] -= steps;
      steps += a[i] + b[i];
      ans += steps;
    }
    cout << ans << endl;
  }
  return 0;
}