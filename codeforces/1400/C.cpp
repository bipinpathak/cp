#include <bits/stdc++.h>
using namespace std;
void solve() {
  int x, i, n;
  string s, ans;
  cin >> s >> x;
  n = s.length();
  vector<int> store(n, 1);
  for (i = 0; i < n; i++) {
    if (s[i] == '0') {
      if (i - x >= 0) {
        store[i-x] = 0;
      }
      if (i + x < n) {
        store[i+x] = 0;
      }
    }
  }
  for (i = 0; i < n; i++) {
    if (s[i] == '1' && !((i - x >= 0 && store[i - x] == 1) || (i + x < n && store[i + x] == 1))) {
      ans = "-1";
      break;
    }
    ans = ans + to_string(store[i]);
  }
  cout << ans << endl;
}
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
    solve();
  }
  return 0;
}