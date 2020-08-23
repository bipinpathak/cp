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
    int n, i, x;
    string ans = "YES";
    cin >> n;
    vector<int> a(n), b;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    b = a;
    sort(b.begin(), b.end());
    x = b[0];
    for (i = 0; i < n && ans == "YES"; i++) {
      if (a[i] != b[i] && a[i] % x != 0) {
        ans = "NO";
      }
    }
    cout << ans << endl;
  }
  return 0;
}