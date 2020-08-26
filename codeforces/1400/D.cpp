#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, i, j, ans = 0;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> dp(n, vector<int>(n, 0));
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (i) {
      dp[i] = dp[i - 1];
    }
    dp[i][a[i] - 1]++;
  }
  for (i = 1; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      ans += (dp[n - 1][a[i] - 1] - dp[j][a[i] - 1]) * dp[i - 1][a[j] - 1];
    }
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