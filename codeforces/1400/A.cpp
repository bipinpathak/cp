#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, i;
  string s, ans="";
  cin >> n >> s;
  for (i = 0; i < n; i++) {
    ans = ans + s[n - 1];
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