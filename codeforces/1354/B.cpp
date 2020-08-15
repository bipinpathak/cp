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
    string s;
    cin >> s;
    vector<int> f(3, -1);
    int i, n = s.length(), ans = n;
    for (i = 0; i < n; i++) {
      int curr = s[i] - '1', start = n, end = -1;
      f[curr] = i;
      start = min(f[0], min(f[1], f[2]));
      end = max(f[0], max(f[1], f[2]));
      if (start != -1) {
        ans = min(ans, end - start + 1);
      }
    }
    if (min(f[0], min(f[1], f[2])) == -1) {
      ans = 0;
    }
    cout << ans << endl;
  }
  return 0;
}